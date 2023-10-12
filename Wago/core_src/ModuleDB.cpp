static const char *RcsId = "$Id: ModuleDB.cpp,v 1.10 2018/06/15 12:48:55 perez Exp $";
/*
 * ModuleDB.cpp
 *
 *  Created on: Mar 5, 2013
 *      Author: kowalisz
 */
#include "ModuleDB.h"
#include "PhysValueTransformer.h"

#include <algorithm>

ModuleDB* ModuleDB::_instance = NULL;

/*!Defaulst constructor.
 *
 */
ModuleDB::ModuleDB()
{

}

/*Destructor - cleans the contents of database and releases physical value transformer objects.
 *
 */
ModuleDB::~ModuleDB()
{
	for(unsigned int i = 0; i<moduleList.size(); i++)
	{
		if(moduleList[i].physTransformer)
			delete moduleList[i].physTransformer;
	}
}

/*Returns pointer to module database instance.
 * The ModuleDB class is based on singleton design pattern.
 * Anny acces to the database shall be done via this method.
 *
 * \return  pointer to moduleDB instance.
 */
ModuleDB* ModuleDB::Instance()
{
	if(!_instance)
		_instance = new ModuleDB();

	return _instance;
}

/*!Find module description with given module reference name.
 *
 * \param reference 	reference name for searched module.
 *
 * \return	pointer to found description or NULL.
 */
wagoModuleDesc* ModuleDB::FindModule(string reference)
{
	for(unsigned int i = 0; i < moduleList.size(); i++)
	{
		if(reference == moduleList[i].name)
		{
			return &moduleList[i];
		}
	}

	return NULL;
}

/*!Referencing signalizes that description structure will be used. If physical value transformer object
 * does not exist new instance will be attached to the description.
 *
 * \param pointer to module descriptor.
 */
void ModuleDB::ReferenceModule(wagoModuleDesc* module)
{
	protectMutex.lock();
	if(module->physTransformer == NULL)
	{
		DB_INFO_STREAM << "ModuleDB::ReferenceModule() attaching physValueTransformer to module: " << module->name << endl;
		try{
			AttachPhysTransformer(*module);
		}catch(...)
		{
			protectMutex.unlock();
			throw;
		}
	}
	module->physTransformer->ReferenceObj();
	DB_INFO_STREAM << "ModuleDB::ReferenceModule() referencing physValueTransformer of module: " <<module->name << endl;
	protectMutex.unlock();
}

/*!Dereferencing signalizes that this description will not be used any more in current context.
 * If ussage counter is equal to zero physical value transformer object related to this
 * description will be freed.
 *
 * \param pointer to module descriptor.
 */
void ModuleDB::DereferenceModule(wagoModuleDesc* module)
{
	if(!module->physTransformer)
		return;


	DB_INFO_STREAM << "ModuleDB dereferencing physValueTransformer of module: " << module->name << endl;
	protectMutex.lock();
	module->physTransformer->DereferenceObj();
	if(!module->physTransformer->GetReferenceCtr())
	{
		delete module->physTransformer;
		module->physTransformer = NULL;
		DB_INFO_STREAM << "ModuleDB deleting physValueTransformer of module: " << module->name << endl;
	}
	protectMutex.unlock();
}

/*! Method for filling the module database with information from given module catalogue text description.
 *
 * \param resources		vector of strings holding a module catalogue description.Each string is one line of description.
 */
void ModuleDB::ParseCatalogue(vector<string> &resources)
{
	moduleList.clear();

	if(resources.empty())
	{
		DB_INFO_STREAM << "Module module catalogue resource is empty" << endl;
		EXCEPTION_RETURN("ModuleDB::ParseCatalogueLine","Module catalogue resource is empty", "Modbus::error_read");
	}

	for(unsigned int i = 0; i < resources.size(); i++)
	{
		string tmp = resources[i];
		tmp.erase(std::remove(tmp.begin(), tmp.end(), '"'), tmp.end());
		vector<string> fields = string2vector(tmp, ",");
		ParseCatalogueLine(fields);
	}

	if(moduleList.empty())
	{
		DB_INFO_STREAM << "Invalid module catalogue" << endl;
		EXCEPTION_RETURN("ModuleDB::ParseCatalogueLine","Invalid module catalogue", "Modbus::error_read");
	}
}

/*! Processes a line of module catalogue description
 *
 * \param liveVals	vector holding each field of catalogue line in separate string.
 */
void ModuleDB::ParseCatalogueLine(vector<string> &lineVals)
{
	wagoModuleDesc buffer;

	buffer.physTransformer = NULL;

	if(lineVals.empty())
		return;

	if(lineVals.size() < 8)
	{
		DB_INFO_STREAM << "invalid num of fields in module catalogue line " << endl;
		EXCEPTION_RETURN("ModuleDB::ParseCatalogueLine","Invalid number of arguments in module catalogue line", "Modbus::error_read");
	}

	buffer.name = lineVals[0];
	buffer.name.erase( std::remove_if( buffer.name.begin(), buffer.name.end(), ::isspace ), buffer.name.end() );

	int tmp1, tmp2;
	if(sscanf(lineVals[0].c_str(),"%d-%d",&tmp1, &tmp2) != 2)
	{
		DB_INFO_STREAM << lineVals[0] <<" - Invalid module name in module catalogue" << endl;
		EXCEPTION_RETURN("ModuleDB::ParseCatalogueLine","Invalid module name in module catalogue", "Modbus::error_read");
	}
	if(tmp1 != 750)
	{
		DB_INFO_STREAM << tmp1 <<" - Invalid module series in module catalogue" << endl;
		EXCEPTION_RETURN("ModuleDB::ParseCatalogueLine","Invalid module series in module catalogue", "Modbus::error_read");
	}

	buffer.modCode = tmp2;
	int val;

	if((sscanf(lineVals[5].c_str(), "%d", &val) != 1)  || !val)
	{
		DB_INFO_STREAM << lineVals[0] << " - Invalid number of channels value in module catalogue" << endl;
		EXCEPTION_RETURN("ModuleDB::ParseCatalogueLine","Invalid number of channel value in module catalogue", "Modbus::error_read");
	}
	buffer.channels = val;

	if (sscanf(lineVals[1].c_str(), "%d", &val) != 1)
	{
		DB_INFO_STREAM << lineVals[0] << " - Invalid digital input value in module catalogue" << endl;
		EXCEPTION_RETURN("ModuleDB::ParseCatalogueLine","Invalid digital input value value in module catalogue", "Modbus::error_read");
	}
	buffer.digi_in = val/buffer.channels;

	if (sscanf(lineVals[2].c_str(), "%d", &val) != 1)
	{
		DB_INFO_STREAM << lineVals[0] << " - Invalid digital output value in module catalogue" << endl;
		EXCEPTION_RETURN("ModuleDB::ParseCatalogueLine","Invalid digital output value value in module catalogue", "Modbus::error_read");
	}
	buffer.digi_out = val/buffer.channels;

	if (sscanf(lineVals[3].c_str(), "%d", &val) != 1)
	{
		DB_INFO_STREAM << lineVals[0] << " - Invalid analog input value in module catalogue" << endl;
		EXCEPTION_RETURN("ModuleDB::ParseCatalogueLine","Invalid analog input value value in module catalogue", "Modbus::error_read");
	}
	buffer.ana_in = val/buffer.channels;

	if (sscanf(lineVals[4].c_str(), "%d", &val) != 1)
	{
		DB_INFO_STREAM << lineVals[0] << " - Invalid analog output value in module catalogue" << endl;
		EXCEPTION_RETURN("ModuleDB::ParseCatalogueLine","Invalid output input value value in module catalogue", "Modbus::error_read");
	}
	buffer.ana_out = val/buffer.channels;

	if((buffer.digi_in) && (buffer.digi_out))
		buffer.mtype = BINARY_OUTPUT;
        else if(buffer.digi_in)
		buffer.mtype = BINARY_INPUT;
	else if(buffer.digi_out)
		buffer.mtype = BINARY_OUTPUT;
	else if(buffer.ana_in)
		buffer.mtype = REGISTER_INPUT;
	else if(buffer.ana_out)
		buffer.mtype = REGISTER_OUTPUT;

	buffer.special = lineVals[6];
	buffer.special.erase(std::remove(buffer.special.begin(), buffer.special.end(), ' '), buffer.special.end());

	buffer.description = lineVals[7];

	moduleList.push_back(buffer);
}

/*! Attach physical value transformer object to given module description.
 *
 * \param modDesc	reference to module description structure.
 */
void ModuleDB::AttachPhysTransformer(wagoModuleDesc &modDesc)
{
	if(strncmp(modDesc.special.c_str(), FS_RES, strlen(FS_RES)) == 0)
	{
			DB_INFO_STREAM << "ModuleDB::AttachPhysTransformer() " << modDesc.name << " attaching FsTransformer" << endl;
			modDesc.physTransformer = new FsTransformer();
	}
	else if(strncmp(modDesc.special.c_str(), THC_100_RES, strlen(THC_100_RES)) == 0)
	{
			DB_INFO_STREAM << "ModuleDB::AttachPhysTransformer() " << modDesc.name << " attaching Thc100Transformer" << endl;
			modDesc.physTransformer = new Thc100Transformer();
	}
        else if(strncmp(modDesc.special.c_str(), THC_RES, strlen(THC_RES)) == 0)
	{
			DB_INFO_STREAM << "ModuleDB::AttachPhysTransformer() " << modDesc.name << " attaching ThcTransformer" << endl;
			modDesc.physTransformer = new ThcTransformer();
	}
	else if(strncmp(modDesc.special.c_str(), SSI_RES, strlen(SSI_RES)) == 0)
	{
			DB_INFO_STREAM << "ModuleDB::AttachPhysTransformer() " << modDesc.name << " attaching SSITransformer" << endl;
			modDesc.physTransformer = new SSITransformer();
	}
	else if(strncmp(modDesc.special.c_str(), M637_RES, strlen(M637_RES)) == 0)
	{
			DB_INFO_STREAM << "ModuleDB::AttachPhysTransformer() " << modDesc.name << " attaching 637 transformer(Configurable transformer)" << endl;
			modDesc.physTransformer = new ConfigurableSizePhysTransformer(32, 1.0, false);
	}
	else
	{
		DB_INFO_STREAM << "ModuleDB::AttachPhysTransformer() " << modDesc.name << " attaching PhysValueTransformer" << endl;
		modDesc.physTransformer = new PhysValueTransformer;
	}

	try
	{
		modDesc.physTransformer->Setup(modDesc);
	}catch(...)
	{
		delete modDesc.physTransformer;
		modDesc.physTransformer = NULL;
		throw;
	}

}
