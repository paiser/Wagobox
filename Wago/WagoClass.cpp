/*----- PROTECTED REGION ID(WagoClass.cpp) ENABLED START -----*/
static const char *RcsId      = "$Id: WagoClass.cpp,v 1.10 2018/01/19 12:15:31 perez Exp $";
static const char *TagName    = "$Name: Wago-Release_2_10 $";
static const char *CvsPath    = "$Source: /segfs/tango/cvsroot/cppserver/instrumentation/Wago/WagoClass.cpp,v $";
static const char *SvnPath    = "$HeadURL:  $";
static const char *HttpServer = "http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/";
//=============================================================================
//
// file :        WagoClass.cpp
//
// description : C++ source for the WagoClass.
//               A singleton class derived from DeviceClass.
//               It implements the command and attribute list
//               and all properties and methods required
//               by the Wago once per process.
//
// project :     Wago controller interface
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
// $Author: perez $
//
// $Revision: 1.10 $
// $Date: 2018/01/19 12:15:31 $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#include <WagoClass.h>
#include "./core_src/ModuleDB.h"

/*----- PROTECTED REGION END -----*/	//	WagoClass.cpp

//-------------------------------------------------------------------
/**
 *	Create WagoClass singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_Wago_class(const char *name) {
		return Wago_ns::WagoClass::init(name);
	}
}

namespace Wago_ns
{
//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
WagoClass *WagoClass::_instance = NULL;

//===================================================================
//	Class constants
//===================================================================
//--------------------------------------------------------
/**
 * method : 		WagoClass::WagoClass(std::string &s)
 * description : 	constructor for the WagoClass
 *
 * @param s	The class name
 */
//--------------------------------------------------------
WagoClass::WagoClass(std::string &s):Tango::DeviceClass(s)
{
	TANGO_LOG_INFO << "Entering WagoClass constructor" << std::endl;
	set_default_property();
	get_class_property();
	write_class_property();

	/*----- PROTECTED REGION ID(WagoClass::constructor) ENABLED START -----*/
	ModuleDB::Instance()->ParseCatalogue(modulesCatalogue);
	/*----- PROTECTED REGION END -----*/	//	WagoClass::constructor

	TANGO_LOG_INFO << "Leaving WagoClass constructor" << std::endl;
}

//--------------------------------------------------------
/**
 * method : 		WagoClass::~WagoClass()
 * description : 	destructor for the WagoClass
 */
//--------------------------------------------------------
WagoClass::~WagoClass()
{
	/*----- PROTECTED REGION ID(WagoClass::destructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	WagoClass::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		WagoClass::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
WagoClass *WagoClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			std::string s(name);
			_instance = new WagoClass(s);
		}
		catch (std::bad_alloc &)
		{
			throw;
		}
	}
	return _instance;
}

//--------------------------------------------------------
/**
 * method : 		WagoClass::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
WagoClass *WagoClass::instance()
{
	if (_instance == NULL)
	{
		std::cerr << "Class is not initialized !!" << std::endl;
		exit(-1);
	}
	return _instance;
}



//===================================================================
//	Command execution method calls
//===================================================================
//--------------------------------------------------------
/**
 * method : 		DevReadNoCachePhysClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevReadNoCachePhysClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	TANGO_LOG_INFO << "DevReadNoCachePhysClass::execute(): arrived" << std::endl;
	Tango::DevShort argin;
	extract(in_any, argin);
	return insert((static_cast<Wago *>(device))->dev_read_no_cache_phys(argin));
}

//--------------------------------------------------------
/**
 * method : 		DevWritePhysClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevWritePhysClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	TANGO_LOG_INFO << "DevWritePhysClass::execute(): arrived" << std::endl;
	const Tango::DevVarFloatArray *argin;
	extract(in_any, argin);
	((static_cast<Wago *>(device))->dev_write_phys(argin));
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		DevReadPhysClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevReadPhysClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	TANGO_LOG_INFO << "DevReadPhysClass::execute(): arrived" << std::endl;
	Tango::DevShort argin;
	extract(in_any, argin);
	return insert((static_cast<Wago *>(device))->dev_read_phys(argin));
}

//--------------------------------------------------------
/**
 * method : 		DevWriteDigiClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevWriteDigiClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	TANGO_LOG_INFO << "DevWriteDigiClass::execute(): arrived" << std::endl;
	const Tango::DevVarShortArray *argin;
	extract(in_any, argin);
	((static_cast<Wago *>(device))->dev_write_digi(argin));
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		DevReadDigiClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevReadDigiClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	TANGO_LOG_INFO << "DevReadDigiClass::execute(): arrived" << std::endl;
	Tango::DevShort argin;
	extract(in_any, argin);
	return insert((static_cast<Wago *>(device))->dev_read_digi(argin));
}

//--------------------------------------------------------
/**
 * method : 		DevReadNoCacheDigiClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevReadNoCacheDigiClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	TANGO_LOG_INFO << "DevReadNoCacheDigiClass::execute(): arrived" << std::endl;
	Tango::DevShort argin;
	extract(in_any, argin);
	return insert((static_cast<Wago *>(device))->dev_read_no_cache_digi(argin));
}

//--------------------------------------------------------
/**
 * method : 		DevGetKeysClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevGetKeysClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	TANGO_LOG_INFO << "DevGetKeysClass::execute(): arrived" << std::endl;
	return insert((static_cast<Wago *>(device))->dev_get_keys());
}

//--------------------------------------------------------
/**
 * method : 		DevKey2NameClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevKey2NameClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	TANGO_LOG_INFO << "DevKey2NameClass::execute(): arrived" << std::endl;
	Tango::DevShort argin;
	extract(in_any, argin);
	return insert((static_cast<Wago *>(device))->dev_key2_name(argin));
}

//--------------------------------------------------------
/**
 * method : 		DevLog2HardClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevLog2HardClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	TANGO_LOG_INFO << "DevLog2HardClass::execute(): arrived" << std::endl;
	const Tango::DevVarShortArray *argin;
	extract(in_any, argin);
	return insert((static_cast<Wago *>(device))->dev_log2_hard(argin));
}

//--------------------------------------------------------
/**
 * method : 		DevHard2LogClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevHard2LogClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	TANGO_LOG_INFO << "DevHard2LogClass::execute(): arrived" << std::endl;
	const Tango::DevVarShortArray *argin;
	extract(in_any, argin);
	return insert((static_cast<Wago *>(device))->dev_hard2_log(argin));
}

//--------------------------------------------------------
/**
 * method : 		DevName2KeyClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevName2KeyClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	TANGO_LOG_INFO << "DevName2KeyClass::execute(): arrived" << std::endl;
	Tango::DevString argin;
	extract(in_any, argin);
	return insert((static_cast<Wago *>(device))->dev_name2_key(argin));
}

//--------------------------------------------------------
/**
 * method : 		DevWcCommClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevWcCommClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	TANGO_LOG_INFO << "DevWcCommClass::execute(): arrived" << std::endl;
	const Tango::DevVarShortArray *argin;
	extract(in_any, argin);
	return insert((static_cast<Wago *>(device))->dev_wc_comm(argin));
}


//===================================================================
//	Properties management
//===================================================================
//--------------------------------------------------------
/**
 *	Method     : WagoClass::get_class_property()
 *	Description: Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum WagoClass::get_class_property(std::string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method     : WagoClass::get_default_device_property()
 *	Description: Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum WagoClass::get_default_device_property(std::string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method     : WagoClass::get_default_class_property()
 *	Description: Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum WagoClass::get_default_class_property(std::string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method     : WagoClass::get_class_property()
 *	Description: Read database to initialize class property data members.
 */
//--------------------------------------------------------
void WagoClass::get_class_property()
{
	/*----- PROTECTED REGION ID(WagoClass::get_class_property_before) ENABLED START -----*/
	
	//	Initialize class property data members
	
	/*----- PROTECTED REGION END -----*/	//	WagoClass::get_class_property_before
	//	Read class properties from database.
	cl_prop.push_back(Tango::DbDatum("modulesCatalogue"));

	//	Call database and extract values
	if (Tango::Util::instance()->_UseDb==true)
		get_db_class()->get_property(cl_prop);
	Tango::DbDatum	def_prop;
	int	i = -1;

	//	Try to extract modulesCatalogue value
	if (cl_prop[++i].is_empty()==false)	cl_prop[i]  >>  modulesCatalogue;
	else
	{
		//	Check default value for modulesCatalogue
		def_prop = get_default_class_property(cl_prop[i].name);
		if (def_prop.is_empty()==false)
		{
			def_prop    >>  modulesCatalogue;
			cl_prop[i]  <<  modulesCatalogue;
		}
	}
	/*----- PROTECTED REGION ID(WagoClass::get_class_property_after) ENABLED START -----*/
	
	//	Check class property data members init
	
	/*----- PROTECTED REGION END -----*/	//	WagoClass::get_class_property_after

}

//--------------------------------------------------------
/**
 *	Method     : WagoClass::set_default_property()
 *	Description: Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void WagoClass::set_default_property()
{
	std::string	prop_name;
	std::string	prop_desc;
	std::string	prop_def;
	std::vector<std::string>	vect_data;

	//	Set Default Class Properties
	prop_name = "modulesCatalogue";
	prop_desc = "List of know WAGO modules usable by the WAGO Device Server\nSYNTAX: \n   -the first item should be the date the list has been updated\n   -then, for each module, you must supply:\n          -module reference\n          -number of digital  inputs\n          -number of digital outputs\n          -number of word     inputs\n          -number of word    outputs\n          -number of logical channels (typically SSI32bits==2 words)\n          -string for special module  (``none``,``ssi``,``thc``,``thc100``,``thck``,etc)\n          -string for description";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		cl_def_prop.push_back(data);
		add_wiz_class_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_class_prop(prop_name, prop_desc);

	//	Set Default device Properties
	prop_name = "modbusDevName";
	prop_desc = "Name of Modbus tango device server used for communication with\n physical device.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "config";
	prop_desc = "Configuration of physical modules in device and its projection\n to LogicalDevices in server.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "updatePeriod";
	prop_desc = "Modbus process image cache update interval.";
	prop_def  = "1000";
	vect_data.clear();
	vect_data.push_back("1000");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
}

//--------------------------------------------------------
/**
 *	Method     : WagoClass::write_class_property()
 *	Description: Set class description fields as property in database
 */
//--------------------------------------------------------
void WagoClass::write_class_property()
{
	//	First time, check if database used
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	std::string	classname = get_name();
	std::string	header;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	std::string	str_title("Wago interface");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	std::vector<std::string>	str_desc;
	str_desc.push_back("Device server for Wago 750 series Programable Fieldbus Controllers ");
	str_desc.push_back("and Fieldbus Couplers. The class supports reading and writing to a node");
	str_desc.push_back("consisting of a number of Wago modules. It communicates with device over");
	str_desc.push_back("Modbus TCP or RTU protocol by means of Modbus Tango class.");
	description << str_desc;
	data.push_back(description);

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	std::vector<std::string> inheritance;
	inheritance.push_back("TANGO_BASE_CLASS");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	get_db_class()->put_property(data);
}

//===================================================================
//	Factory methods
//===================================================================

//--------------------------------------------------------
/**
 *	Method     : WagoClass::device_factory()
 *	Description: Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void WagoClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
	/*----- PROTECTED REGION ID(WagoClass::device_factory_before) ENABLED START -----*/
	
	//	Add your own code
	//TODO Move ModuleDB initialisation here;
	
	//ModuleDB::Instance()->ParseCatalogue(modulesCatalogue);

	/*----- PROTECTED REGION END -----*/	//	WagoClass::device_factory_before

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		TANGO_LOG_DEBUG << "Device name : " << (*devlist_ptr)[i].in() << std::endl;
		device_list.push_back(new Wago(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		Wago *dev = static_cast<Wago *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	/*----- PROTECTED REGION ID(WagoClass::device_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	WagoClass::device_factory_after
}
//--------------------------------------------------------
/**
 *	Method     : WagoClass::attribute_factory()
 *	Description: Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void WagoClass::attribute_factory(std::vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(WagoClass::attribute_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	WagoClass::attribute_factory_before

	//	Create a list of static attributes
	create_static_attribute_list(get_class_attr()->get_attr_list());
	/*----- PROTECTED REGION ID(WagoClass::attribute_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	WagoClass::attribute_factory_after
}
//--------------------------------------------------------
/**
 *	Method     : WagoClass::pipe_factory()
 *	Description: Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void WagoClass::pipe_factory()
{
	/*----- PROTECTED REGION ID(WagoClass::pipe_factory_before) ENABLED START -----*/
	/* clang-format on */
	//	Add your own code
	/* clang-format off */
	/*----- PROTECTED REGION END -----*/	//	WagoClass::pipe_factory_before
	/*----- PROTECTED REGION ID(WagoClass::pipe_factory_after) ENABLED START -----*/
	/* clang-format on */
	//	Add your own code
	/* clang-format off */
	/*----- PROTECTED REGION END -----*/	//	WagoClass::pipe_factory_after
}
//--------------------------------------------------------
/**
 *	Method     : WagoClass::command_factory()
 *	Description: Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void WagoClass::command_factory()
{
	/*----- PROTECTED REGION ID(WagoClass::command_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	WagoClass::command_factory_before


	//	Command DevReadNoCachePhys
	DevReadNoCachePhysClass	*pDevReadNoCachePhysCmd =
		new DevReadNoCachePhysClass("DevReadNoCachePhys",
			Tango::DEV_SHORT, Tango::DEVVAR_FLOATARRAY,
			"Logical device index.",
			"Array of values.",
			Tango::OPERATOR);
	command_list.push_back(pDevReadNoCachePhysCmd);

	//	Command DevWritePhys
	DevWritePhysClass	*pDevWritePhysCmd =
		new DevWritePhysClass("DevWritePhys",
			Tango::DEVVAR_FLOATARRAY, Tango::DEV_VOID,
			"Logical device key and values for write",
			"",
			Tango::OPERATOR);
	command_list.push_back(pDevWritePhysCmd);

	//	Command DevReadPhys
	DevReadPhysClass	*pDevReadPhysCmd =
		new DevReadPhysClass("DevReadPhys",
			Tango::DEV_SHORT, Tango::DEVVAR_FLOATARRAY,
			"Logical device key",
			"Placeholder for obtained values",
			Tango::OPERATOR);
	command_list.push_back(pDevReadPhysCmd);

	//	Command DevWriteDigi
	DevWriteDigiClass	*pDevWriteDigiCmd =
		new DevWriteDigiClass("DevWriteDigi",
			Tango::DEVVAR_SHORTARRAY, Tango::DEV_VOID,
			"Logical device key, then pairs of channel,value.",
			"",
			Tango::OPERATOR);
	command_list.push_back(pDevWriteDigiCmd);

	//	Command DevReadDigi
	DevReadDigiClass	*pDevReadDigiCmd =
		new DevReadDigiClass("DevReadDigi",
			Tango::DEV_SHORT, Tango::DEVVAR_SHORTARRAY,
			"Logical device",
			"Array of bit values",
			Tango::OPERATOR);
	command_list.push_back(pDevReadDigiCmd);

	//	Command DevReadNoCacheDigi
	DevReadNoCacheDigiClass	*pDevReadNoCacheDigiCmd =
		new DevReadNoCacheDigiClass("DevReadNoCacheDigi",
			Tango::DEV_SHORT, Tango::DEVVAR_SHORTARRAY,
			"Logical device",
			"Array of bit values",
			Tango::OPERATOR);
	command_list.push_back(pDevReadNoCacheDigiCmd);

	//	Command DevGetKeys
	DevGetKeysClass	*pDevGetKeysCmd =
		new DevGetKeysClass("DevGetKeys",
			Tango::DEV_VOID, Tango::DEVVAR_SHORTARRAY,
			"",
			"Numerical keys",
			Tango::OPERATOR);
	command_list.push_back(pDevGetKeysCmd);

	//	Command DevKey2Name
	DevKey2NameClass	*pDevKey2NameCmd =
		new DevKey2NameClass("DevKey2Name",
			Tango::DEV_SHORT, Tango::DEV_STRING,
			"Numerical key",
			"Logical device name",
			Tango::OPERATOR);
	command_list.push_back(pDevKey2NameCmd);

	//	Command DevLog2Hard
	DevLog2HardClass	*pDevLog2HardCmd =
		new DevLog2HardClass("DevLog2Hard",
			Tango::DEVVAR_SHORTARRAY, Tango::DEVVAR_SHORTARRAY,
			"[0] : logical device key\n[1] : logical channel",
			"[0] : offset in wago controller memory (ex: 0x16)\n[1] : MSB=I/O LSB=Bit/Word (ex: 0x4957 = (`I`<<8)+`W`)\n[2] : module reference (ex: 469)\n[3] : module number (1st is 0)\n[4] : physical channel of the module (ex: 1 for the 2nd)",
			Tango::OPERATOR);
	command_list.push_back(pDevLog2HardCmd);

	//	Command DevHard2Log
	DevHard2LogClass	*pDevHard2LogCmd =
		new DevHard2LogClass("DevHard2Log",
			Tango::DEVVAR_SHORTARRAY, Tango::DEVVAR_SHORTARRAY,
			"[0] : MSB=I/O LSB=Bit/Word (ex: 0x4957 = (`I`<<8)+`W`)\n[1] : offset in wago controller memory (ex: 0x16)",
			"[0] : logical device key\n[1] : logical channel",
			Tango::OPERATOR);
	command_list.push_back(pDevHard2LogCmd);

	//	Command DevName2Key
	DevName2KeyClass	*pDevName2KeyCmd =
		new DevName2KeyClass("DevName2Key",
			Tango::DEV_STRING, Tango::DEV_SHORT,
			"Logical device name",
			"Numerical key",
			Tango::OPERATOR);
	command_list.push_back(pDevName2KeyCmd);

	//	Command DevWcComm
	DevWcCommClass	*pDevWcCommCmd =
		new DevWcCommClass("DevWcComm",
			Tango::DEVVAR_SHORTARRAY, Tango::DEVVAR_SHORTARRAY,
			"[0] : code of command to execute (ex: 0x010c for ILCK_RESET)\n[1] : 1st parameter\n[2] : 2nd parameter\netc",
			"[0] : 1st argout or error code\n[1] : 2nd argout \netc",
			Tango::OPERATOR);
	command_list.push_back(pDevWcCommCmd);

	/*----- PROTECTED REGION ID(WagoClass::command_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	WagoClass::command_factory_after
}

//===================================================================
//	Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method : 		WagoClass::create_static_attribute_list
 * description : 	Create the a list of static attributes
 *
 * @param	att_list	the created attribute list
 */
//--------------------------------------------------------
void WagoClass::create_static_attribute_list(std::vector<Tango::Attr *> &att_list)
{
	for (unsigned long i=0 ; i<att_list.size() ; i++)
	{
		std::string att_name(att_list[i]->get_name());
		transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
		defaultAttList.push_back(att_name);
	}

	TANGO_LOG_INFO << defaultAttList.size() << " attributes in default list" << std::endl;

	/*----- PROTECTED REGION ID(WagoClass::create_static_att_list) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	WagoClass::create_static_att_list
}


//--------------------------------------------------------
/**
 * method : 		WagoClass::erase_dynamic_attributes
 * description : 	delete the dynamic attributes if any.
 *
 * @param	devlist_ptr	the device list pointer
 * @param	list of all attributes
 */
//--------------------------------------------------------
void WagoClass::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, std::vector<Tango::Attr *> &att_list)
{
	Tango::Util *tg = Tango::Util::instance();

	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((std::string)(*devlist_ptr)[i]).c_str());
		Wago *dev = static_cast<Wago *> (dev_impl);

		std::vector<Tango::Attribute *> &dev_att_list = dev->get_device_attr()->get_attribute_list();
		std::vector<Tango::Attribute *>::iterator ite_att;
		for (ite_att=dev_att_list.begin() ; ite_att != dev_att_list.end() ; ++ite_att)
		{
			std::string att_name((*ite_att)->get_name_lower());
			if ((att_name == "state") || (att_name == "status"))
				continue;
			std::vector<std::string>::iterator ite_str = find(defaultAttList.begin(), defaultAttList.end(), att_name);
			if (ite_str == defaultAttList.end())
			{
				TANGO_LOG_INFO << att_name << " is a UNWANTED dynamic attribute for device " << (*devlist_ptr)[i] << std::endl;
				Tango::Attribute &att = dev->get_device_attr()->get_attr_by_name(att_name.c_str());
				dev->remove_attribute(att_list[att.get_attr_idx()], true, false);
				--ite_att;
			}
		}
	}
	/*----- PROTECTED REGION ID(WagoClass::erase_dynamic_attributes) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	WagoClass::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Method     : WagoClass::get_attr_object_by_name()
 *	Description: returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *WagoClass::get_attr_object_by_name(std::vector<Tango::Attr *> &att_list, std::string attname)
{
	std::vector<Tango::Attr *>::iterator it;
	for (it=att_list.begin() ; it<att_list.end() ; ++it)
		if ((*it)->get_name()==attname)
			return (*it);
	//	Attr does not exist
	return NULL;
}


/*----- PROTECTED REGION ID(WagoClass::Additional Methods) ENABLED START -----*/

/*----- PROTECTED REGION END -----*/	//	WagoClass::Additional Methods
} //	namespace