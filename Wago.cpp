/*----- PROTECTED REGION ID(Wago.cpp) ENABLED START -----*/
static const char *RcsId = "$Id: Wago.cpp,v 1.19 2018/06/15 12:55:16 perez Exp $";
//=============================================================================
//
// file :        Wago.cpp
//
// description : C++ source for the Wago class and its commands.
//               The class is derived from Device. It represents the
//               CORBA servant object which will be accessed from the
//               network. All commands which can be executed on the
//               Wago are implemented in this file.
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
// $Revision: 1.19 $
// $Date: 2018/06/15 12:55:16 $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#include <Wago.h>
#include <WagoClass.h>
#include "ModbusConn.h"
#include "./core_src/Configurator.h"

/*----- PROTECTED REGION END -----*/	//	Wago.cpp

/**
 *  Wago class description:
 *    Device server for Wago 750 series Programable Fieldbus Controllers 
 *    and Fieldbus Couplers. The class supports reading and writing to a node
 *    consisting of a number of Wago modules. It communicates with device over
 *    Modbus TCP or RTU protocol by means of Modbus Tango class.
 */

//================================================================
//  The following table gives the correspondence
//  between command and method names.
//
//  Command name        |  Method name
//================================================================
//  State               |  dev_state
//  Status              |  dev_status
//  DevReadNoCachePhys  |  dev_read_no_cache_phys
//  DevWritePhys        |  dev_write_phys
//  DevReadPhys         |  dev_read_phys
//  DevWriteDigi        |  dev_write_digi
//  DevReadDigi         |  dev_read_digi
//  DevReadNoCacheDigi  |  dev_read_no_cache_digi
//  DevGetKeys          |  dev_get_keys
//  DevKey2Name         |  dev_key2_name
//  DevLog2Hard         |  dev_log2_hard
//  DevHard2Log         |  dev_hard2_log
//  DevName2Key         |  dev_name2_key
//  DevWcComm           |  dev_wc_comm
//================================================================

//================================================================
//  Attributes managed is:
//================================================================
//================================================================

namespace Wago_ns
{
/*----- PROTECTED REGION ID(Wago::namespace_starting) ENABLED START -----*/

//	static initializations

/*----- PROTECTED REGION END -----*/	//	Wago::namespace_starting

//--------------------------------------------------------
/**
 *	Method      : Wago::Wago()
 *	Description : Constructors for a Tango device
 *                implementing the classWago
 */
//--------------------------------------------------------
Wago::Wago(Tango::DeviceClass *cl, string &s)
 : Tango::Device_4Impl(cl, s.c_str())
{
	/*----- PROTECTED REGION ID(Wago::constructor_1) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	Wago::constructor_1
}
//--------------------------------------------------------
Wago::Wago(Tango::DeviceClass *cl, const char *s)
 : Tango::Device_4Impl(cl, s)
{
	/*----- PROTECTED REGION ID(Wago::constructor_2) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	Wago::constructor_2
}
//--------------------------------------------------------
Wago::Wago(Tango::DeviceClass *cl, const char *s, const char *d)
 : Tango::Device_4Impl(cl, s, d)
{
	/*----- PROTECTED REGION ID(Wago::constructor_3) ENABLED START -----*/

	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	Wago::constructor_3
}

//--------------------------------------------------------
/**
 *	Method      : Wago::delete_device()
 *	Description : will be called at device destruction or at init command
 */
//--------------------------------------------------------
void Wago::delete_device()
{
	DEBUG_STREAM << "Wago::delete_device() " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::delete_device) ENABLED START -----*/
	
	//	Delete device allocated objects
	if(wd)
		delete wd;

	if(mbDevState)
		delete mbDevState;

	if(modbusDevProxyObj)
		delete modbusDevProxyObj;

	//scallarAttributeValues, spectrumAtributeValues are not cleaned on purpose.
	//If scallarAttributeValues, spectrumAtributeValues cleaned here the Init service
	//doesn´t work properly (atkmon fails to print attribute value charts).
	/*----- PROTECTED REGION END -----*/	//	Wago::delete_device
}

//--------------------------------------------------------
/**
 *	Method      : Wago::init_device()
 *	Description : will be called at device initialization.
 */
//--------------------------------------------------------
void Wago::init_device()
{
	DEBUG_STREAM << "Wago::init_device() create device " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::init_device_before) ENABLED START -----*/
	//logInst = new Tango::LogAdapter(this); 
        //(setup logging for underlying layer. TODO this should be in constructor 
        //(issue: pogo generates destructor without protected region )

	//	Initialization before get_device_property() call
	
	/*----- PROTECTED REGION END -----*/	//	Wago::init_device_before
	

	//	Get the device properties from database
	get_device_property();
	

	/*----- PROTECTED REGION ID(Wago::init_device) ENABLED START -----*/
	WagoClass	*ds_class =
		(static_cast<WagoClass *>(get_device_class()));

	//ModuleDB::Instance()->ParseCatalogue(ds_class->modulesCatalogue);
	mbDevState = new DeviceState(this);
	mbDevState->SetState(Tango::INIT);

	wd = new WagoDevice();
	LOGGING_INITIALIZE_WITH_LOGGER_REF_ADDON(wd, this->get_logger());
	BufferHolder *bh = &(wd->buffers);
	LOGGING_INITIALIZE_WITH_LOGGER_REF_ADDON(bh, this->get_logger());

	try{
		modbusDevProxyObj = new Tango::DeviceProxy(modbusDevName);
		modbusDevProxyObj->set_timeout_millis(500);
	}catch (const Tango::DevFailed &ex)
	{
		mbDevState->SetState(Tango::FAULT);
		mbDevState->setLastException(ex);
		modbusDevProxyObj = NULL;
		return;
	}

	Configurator* cfg = new Configurator(wd);
	LOGGING_INITIALIZE_WITH_LOGGER_REF_ADDON(cfg, this->get_logger());
	try{
		cfg->ParseConfiguration(config);
	}catch(Tango::DevFailed &ex)
	{
		mbDevState->SetState(Tango::FAULT);
		mbDevState->setLastException(ex);
	}

	ModbusConn* mbConnectionObj = new ModbusConn(modbusDevProxyObj, this, mbDevState);
	cfg->SetModbusDevice(mbConnectionObj, updatePeriod);

	delete cfg;

	//	Initialize device
	
	/*----- PROTECTED REGION END -----*/	//	Wago::init_device
}

//--------------------------------------------------------
/**
 *	Method      : Wago::get_device_property()
 *	Description : Read database to initialize property data members.
 */
//--------------------------------------------------------
void Wago::get_device_property()
{
	/*----- PROTECTED REGION ID(Wago::get_device_property_before) ENABLED START -----*/
	
	//	Initialize property data members
	
	/*----- PROTECTED REGION END -----*/	//	Wago::get_device_property_before


	//	Read device properties from database.
	Tango::DbData	dev_prop;
	dev_prop.push_back(Tango::DbDatum("modbusDevName"));
	dev_prop.push_back(Tango::DbDatum("config"));
	dev_prop.push_back(Tango::DbDatum("updatePeriod"));

	//	is there at least one property to be read ?
	if (dev_prop.size()>0)
	{
		//	Call database and extract values
		if (Tango::Util::instance()->_UseDb==true)
			get_db_device()->get_property(dev_prop);
	
		//	get instance on WagoClass to get class property
		Tango::DbDatum	def_prop, cl_prop;
		WagoClass	*ds_class =
			(static_cast<WagoClass *>(get_device_class()));
		int	i = -1;

		//	Try to initialize modbusDevName from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  modbusDevName;
		else {
			//	Try to initialize modbusDevName from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  modbusDevName;
		}
		//	And try to extract modbusDevName value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  modbusDevName;

		//	Try to initialize config from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  config;
		else {
			//	Try to initialize config from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  config;
		}
		//	And try to extract config value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  config;

		//	Try to initialize updatePeriod from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  updatePeriod;
		else {
			//	Try to initialize updatePeriod from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  updatePeriod;
		}
		//	And try to extract updatePeriod value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  updatePeriod;

	}

	/*----- PROTECTED REGION ID(Wago::get_device_property_after) ENABLED START -----*/
	
	//	Check device property data members init
	
	/*----- PROTECTED REGION END -----*/	//	Wago::get_device_property_after
}

//--------------------------------------------------------
/**
 *	Method      : Wago::always_executed_hook()
 *	Description : method always executed before any command is executed
 */
//--------------------------------------------------------
void Wago::always_executed_hook()
{
	DEBUG_STREAM << "Wago::always_executed_hook()  " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::always_executed_hook) ENABLED START -----*/
	
	//	code always executed before all requests
	
	/*----- PROTECTED REGION END -----*/	//	Wago::always_executed_hook
}

//--------------------------------------------------------
/**
 *	Method      : Wago::read_attr_hardware()
 *	Description : Hardware acquisition for attributes
 */
//--------------------------------------------------------
void Wago::read_attr_hardware(TANGO_UNUSED(vector<long> &attr_list))
{
	DEBUG_STREAM << "Wago::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
	/*----- PROTECTED REGION ID(Wago::read_attr_hardware) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Wago::read_attr_hardware
}


//--------------------------------------------------------
/**
 *	Method      : Wago::add_dynamic_attributes()
 *	Description : Create the dynamic attributes if any
 *                for specified device.
 */
//--------------------------------------------------------
void Wago::add_dynamic_attributes()
{
	/*----- PROTECTED REGION ID(Wago::add_dynamic_attributes) ENABLED START -----*/
	
	scallarAttributeValues.clear();
	spectrumAtributeValues.clear();

	Tango::Attr *new_attr;

	LogicalDevice *ld;
	for(unsigned int i =0; ld = wd->GetLd(i);i++)
	{
		Tango::AttrWriteType w_type = Tango::READ_WRITE;

		for(unsigned  int j =0 ; logDeviceValueMapping* chmap = ld->GetChannel(j); j++)
		{
			if(!chmap->module->GetNumOfOutputs())
				w_type = Tango::READ;
		}

		string attName = ld->GetName();
		int chanNum = ld->GetNumOfChannels();
		if( chanNum > 1)
		{
			spectrumAttribBuf_t tmp;
			wd->Name2Key(attName, tmp.key);
			new_attr = new WagoSpectAttrib(attName.c_str(),
														Tango::DEV_FLOAT,
														w_type, chanNum);
			spectrumAtributeValues.insert(make_pair(attName, tmp));
		}
		else
		{
			scallarAttribBuf_t tmp;
			wd->Name2Key(attName, tmp.key);
			new_attr = new WagoScalarAttrib(attName.c_str(),
														Tango::DEV_FLOAT,
														w_type);

			scallarAttributeValues.insert(make_pair(attName, tmp));
		}

		DEBUG_STREAM << "Wago::add_dynamic_attributes() dev: " << this->device_name << "  attr: "  << ld->GetName() << endl;


		add_attribute(new_attr);
	}

	//	Add your own code to create and add dynamic attributes if any
	
	/*----- PROTECTED REGION END -----*/	//	Wago::add_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Command State related method
 *	Description: This command gets the device state (stored in its device_state data member) and returns it to the caller.
 *
 *	@returns Device state
 */
//--------------------------------------------------------
Tango::DevState Wago::dev_state()
{
	DEBUG_STREAM << "Wago::State()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::dev_state) ENABLED START -----*/
	
	Tango::DevState argout = mbDevState->GetState();
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Wago::dev_state
	set_state(argout);    // Give the state to Tango.
	if (argout!=Tango::ALARM)
		DeviceImpl::dev_state();
	return get_state();  // Return it after Tango management.
}
//--------------------------------------------------------
/**
 *	Command Status related method
 *	Description: This command gets the device status (stored in its device_status data member) and returns it to the caller.
 *
 *	@returns Device status
 */
//--------------------------------------------------------
Tango::ConstDevString Wago::dev_status()
{
	DEBUG_STREAM << "Wago::Status()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::dev_status) ENABLED START -----*/
	
	//	Add your own code
	stringstream ss;
	string status;

	wd->Status(status);

	Tango::DevFailed ex = this->mbDevState->getLastException();
	if(ex.errors.length())
	{
		status += "Last Exception:\n";
		for (unsigned short i = 0; i< ex.errors.length(); i++)
		{
			status = status + "\t" + ex.errors[i].origin.in();
			status += "\n";
			status = status + "\t" + ex.errors[i].desc.in();
			status += "\n";
		}

	}

	/*----- PROTECTED REGION END -----*/	//	Wago::dev_status
	set_status(status);               // Give the status to Tango.
	return DeviceImpl::dev_status();  // Return it.
}
//--------------------------------------------------------
/**
 *	Command DevReadNoCachePhys related method
 *	Description: Read all physical values of the specified logical device and 
 *               //              return the values as a float array. Physical value are
 *               //              calculated from module registers according to a predefined
 *               //              algorithm deduced from the module type in the catalogue.
 *               //              Read registers from the cache.
 *               //
 *               //              Note: not all the channels of the logical device are
 *               //              returned but only the ones on modules marked as specials
 *               //              in the catalogue.
 *
 *	@param argin Logical device index.
 *	@returns Array of values.
 */
//--------------------------------------------------------
Tango::DevVarFloatArray *Wago::dev_read_no_cache_phys(Tango::DevShort argin)
{
	Tango::DevVarFloatArray *argout;
	DEBUG_STREAM << "Wago::DevReadNoCachePhys()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::dev_read_no_cache_phys) ENABLED START -----*/

	vector<float> valueHolder;
	wd->ReadPhysNoCache(argin, valueHolder);
	//	Add your own code

	argout = new Tango::DevVarFloatArray();
	argout->length(valueHolder.size());

	for( unsigned int i = 0 ; i < valueHolder.size(); i++)
	{
		DEBUG_STREAM << "dev_read_no_cache_phys returned values[" << i << "]  =" << valueHolder[i] << endl;
		(*argout)[i] = valueHolder[i];
	}
	

	/*----- PROTECTED REGION END -----*/	//	Wago::dev_read_no_cache_phys
	return argout;
}
//--------------------------------------------------------
/**
 *	Command DevWritePhys related method
 *	Description: 
 *
 *	@param argin Logical device key and values for write
 */
//--------------------------------------------------------
void Wago::dev_write_phys(const Tango::DevVarFloatArray *argin)
{
	DEBUG_STREAM << "Wago::DevWritePhys()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::dev_write_phys) ENABLED START -----*/
	if(argin->length() < 3 )
	{
		Tango::Except::throw_exception("Wago::dev_write_phys()","Invalid argument size", "Modbus::error_write");
		return;
	}
	
	unsigned short LdKey = (unsigned short)((*argin)[0]);
	vector<float> valueHolder;
	for( unsigned int i = 1; i < argin->length(); i++ )
		valueHolder.push_back((*argin)[i]);
		
	wd->WritePhys(LdKey, valueHolder);
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Wago::dev_write_phys
}
//--------------------------------------------------------
/**
 *	Command DevReadPhys related method
 *	Description: Read physical values of LD
 *
 *	@param argin Logical device key
 *	@returns Placeholder for obtained values
 */
//--------------------------------------------------------
Tango::DevVarFloatArray *Wago::dev_read_phys(Tango::DevShort argin)
{
	Tango::DevVarFloatArray *argout;
	DEBUG_STREAM << "Wago::DevReadPhys()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::dev_read_phys) ENABLED START -----*/
	vector<float> valueHolder;
	wd->ReadPhys(argin, valueHolder);
	//	Add your own code

	argout = new Tango::DevVarFloatArray();
	argout->length(valueHolder.size());
//	(*argout) << valueHolder;
	for( unsigned int i = 0 ; i < valueHolder.size(); i++)
	{
		DEBUG_STREAM << "dev_read_phys returned values[" << i << "]  =" << valueHolder[i] << endl;
		(*argout)[i] = valueHolder[i];
	}
	/*----- PROTECTED REGION END -----*/	//	Wago::dev_read_phys
	return argout;
}
//--------------------------------------------------------
/**
 *	Command DevWriteDigi related method
 *	Description: Write words and bits to output module registers.
 *
 *	@param argin Logical device key, then pairs of channel,value.
 */
//--------------------------------------------------------
void Wago::dev_write_digi(const Tango::DevVarShortArray *argin)
{
	DEBUG_STREAM << "Wago::DevWriteDigi()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::dev_write_digi) ENABLED START -----*/
	if(argin->length() < 3 )
	{
		Tango::Except::throw_exception("Wago::dev_write_digi()","Invalid argument size", "Modbus::error_write");
		return;
	}

	unsigned short LdKey = (unsigned short)((*argin)[0]);
	vector<unsigned short> valueHolder;
	for( unsigned int i = 1; i < argin->length(); i++ )
		valueHolder.push_back((*argin)[i]);

	wd->WriteDigi(LdKey, valueHolder);
	//	Add your own code

	/*----- PROTECTED REGION END -----*/	//	Wago::dev_write_digi
}
//--------------------------------------------------------
/**
 *	Command DevReadDigi related method
 *	Description: Read all input and output word and bits of the specified logical 
 *               device and return the values as a short array (short per bit). 
 *               Read from the cache.
 *
 *	@param argin Logical device
 *	@returns Array of bit values
 */
//--------------------------------------------------------
Tango::DevVarShortArray *Wago::dev_read_digi(Tango::DevShort argin)
{
	Tango::DevVarShortArray *argout;
	DEBUG_STREAM << "Wago::DevReadDigi()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::dev_read_digi) ENABLED START -----*/
	vector<unsigned short> valueHolder;
	wd->ReadDigi(argin, valueHolder);
	//	Add your own code
	argout = new Tango::DevVarShortArray();
	argout->length(valueHolder.size());
//	(*argout) << valueHolder;
	for( unsigned int i = 0 ; i < valueHolder.size(); i++)
	{
		DEBUG_STREAM << "dev_read_digi returned values[" << i << "]  =" << valueHolder[i] << endl;
		(*argout)[i] = valueHolder[i];
	}
	/*----- PROTECTED REGION END -----*/	//	Wago::dev_read_digi
	return argout;
}
//--------------------------------------------------------
/**
 *	Command DevReadNoCacheDigi related method
 *	Description: Read all input and output word and bits of the specified logical 
 *               device and return the values as a short array (short per bit). 
 *               Read from the cache.
 *
 *	@param argin Logical device
 *	@returns Array of bit values
 */
//--------------------------------------------------------
Tango::DevVarShortArray *Wago::dev_read_no_cache_digi(Tango::DevShort argin)
{
	Tango::DevVarShortArray *argout;
	DEBUG_STREAM << "Wago::DevReadNoCacheDigi()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::dev_read_no_cache_digi) ENABLED START -----*/
	
	vector<unsigned short> valueHolder;
	wd->ReadDigiNoCache(argin, valueHolder);
	//	Add your own code

	argout = new Tango::DevVarShortArray();
	argout->length(valueHolder.size());

	for( unsigned int i = 0 ; i < valueHolder.size(); i++)
	{
		DEBUG_STREAM << "dev_read_no_cache_digi returned values[" << i << "]  =" << valueHolder[i] << endl;
		(*argout)[i] = valueHolder[i];
	}

	
	/*----- PROTECTED REGION END -----*/	//	Wago::dev_read_no_cache_digi
	return argout;
}
//--------------------------------------------------------
/**
 *	Command DevGetKeys related method
 *	Description: Return all the numerical keys known by the server.
 *
 *	@returns Numerical keys
 */
//--------------------------------------------------------
Tango::DevVarShortArray *Wago::dev_get_keys()
{
	Tango::DevVarShortArray *argout;
	DEBUG_STREAM << "Wago::DevGetKeys()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::dev_get_keys) ENABLED START -----*/
	vector<unsigned short> valueHolder;
	
	wd->ReadKeys(valueHolder);
	argout = new Tango::DevVarShortArray();
	argout->length(valueHolder.size());

	for( unsigned int i = 0 ; i < valueHolder.size(); i++)
	{
		DEBUG_STREAM << "dev_get_keys returned values[" << i << "]  =" << valueHolder[i] << endl;
		(*argout)[i] = valueHolder[i];
	}
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Wago::dev_get_keys
	return argout;
}
//--------------------------------------------------------
/**
 *	Command DevKey2Name related method
 *	Description: Return the logical device name associated to a numerical keys 
 *               name.
 *
 *	@param argin Numerical key
 *	@returns Logical device name
 */
//--------------------------------------------------------
Tango::DevString Wago::dev_key2_name(Tango::DevShort argin)
{
	Tango::DevString argout;
	DEBUG_STREAM << "Wago::DevKey2Name()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::dev_key2_name) ENABLED START -----*/
	string valueHolder;
	wd->Key2Name(argin,valueHolder);

	argout = CORBA::string_dup(valueHolder.c_str());

	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Wago::dev_key2_name
	return argout;
}
//--------------------------------------------------------
/**
 *	Command DevLog2Hard related method
 *	Description: Return hardware information of a logical device/logical channel.
 *
 *	@param argin [0] : logical device key
 *               [1] : logical channel
 *	@returns [0] : offset in wago controller memory (ex: 0x16)
 *           [1] : MSB=I/O LSB=Bit/Word (ex: 0x4957 = (`I`<<8)+`W`)
 *           [2] : module reference (ex: 469)
 *           [3] : module number (1st is 0)
 *           [4] : physical channel of the module (ex: 1 for the 2nd)
 */
//--------------------------------------------------------
Tango::DevVarShortArray *Wago::dev_log2_hard(const Tango::DevVarShortArray *argin)
{
	Tango::DevVarShortArray *argout;
	DEBUG_STREAM << "Wago::DevLog2Hard()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::dev_log2_hard) ENABLED START -----*/
	
	vector<unsigned short> valueHolder;
	unsigned short lDevice = (unsigned short)((*argin)[0]);
	unsigned short lChannel = (unsigned short)((*argin)[1]);
	wd->Log2Hard(lDevice, lChannel, valueHolder);

	argout = new Tango::DevVarShortArray();
	argout->length(valueHolder.size());

	for( unsigned int i = 0 ; i < valueHolder.size(); i++)
	{
		DEBUG_STREAM << "dev_log2_hard returned values[" << i << "]  =" << valueHolder[i] << endl;
		(*argout)[i] = valueHolder[i];
	}
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Wago::dev_log2_hard
	return argout;
}
//--------------------------------------------------------
/**
 *	Command DevHard2Log related method
 *	Description: Returns the logical device/logical channel of a memory location 
 *               on wago controller
 *
 *	@param argin [0] : MSB=I/O LSB=Bit/Word (ex: 0x4957 = (`I`<<8)+`W`)
 *               [1] : offset in wago controller memory (ex: 0x16)
 *	@returns [0] : logical device key
 *           [1] : logical channel
 */
//--------------------------------------------------------
Tango::DevVarShortArray *Wago::dev_hard2_log(const Tango::DevVarShortArray *argin)
{
	Tango::DevVarShortArray *argout;
	DEBUG_STREAM << "Wago::DevHard2Log()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::dev_hard2_log) ENABLED START -----*/
	
	vector<unsigned short> valueHolder;

	unsigned short io = (unsigned short)((*argin)[0]);
	unsigned short offset = (unsigned short)((*argin)[1]);
	wd->Hard2LOG(offset, io, valueHolder);

	argout = new Tango::DevVarShortArray();
	argout->length(valueHolder.size());
	for( unsigned int i = 0 ; i < valueHolder.size(); i++)
	{
		DEBUG_STREAM << "dev_hard2_log returned values[" << i << "]  =" << valueHolder[i] << endl;
		(*argout)[i] = valueHolder[i];
	}
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Wago::dev_hard2_log
	return argout;
}
//--------------------------------------------------------
/**
 *	Command DevName2Key related method
 *	Description: Return the logical device name associated to a numerical keys name.
 *
 *	@param argin Logical device name
 *	@returns Numerical key
 */
//--------------------------------------------------------
Tango::DevShort Wago::dev_name2_key(Tango::DevString argin)
{
	Tango::DevShort argout;
	DEBUG_STREAM << "Wago::DevName2Key()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::dev_name2_key) ENABLED START -----*/
	string input(argin);
	wd->Name2Key(input,(unsigned short&)argout);
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Wago::dev_name2_key
	return argout;
}
//--------------------------------------------------------
/**
 *	Command DevWcComm related method
 *	Description: Executes a command in the wago controller programm. The communication is done using the ISG protocol.
 *
 *	@param argin [0] : code of command to execute (ex: 0x010c for ILCK_RESET)
 *               [1] : 1st parameter
 *               [2] : 2nd parameter
 *               etc
 *	@returns [0] : 1st argout or error code
 *           [1] : 2nd argout 
 *           etc
 */
//--------------------------------------------------------
Tango::DevVarShortArray *Wago::dev_wc_comm(const Tango::DevVarShortArray *argin)
{
	Tango::DevVarShortArray *argout;
	DEBUG_STREAM << "Wago::DevWcComm()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Wago::dev_wc_comm) ENABLED START -----*/
	vector<unsigned short> valueHolder,inArgs;

	inArgs.resize(argin->length());
	for( unsigned int i = 0 ; i < argin->length(); i++)
		inArgs[i] = (*argin)[i];

	wd->WcComm(inArgs, valueHolder);
	argout = new Tango::DevVarShortArray();
	argout->length(valueHolder.size());
	for( unsigned int i = 0 ; i < valueHolder.size(); i++)
	{
		DEBUG_STREAM << "WcComm returned values[" << i << "]  =" << valueHolder[i] << endl;
		(*argout)[i] = valueHolder[i];
	}
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Wago::dev_wc_comm
	return argout;
}

/*----- PROTECTED REGION ID(Wago::namespace_ending) ENABLED START -----*/

/*! Method writes value of related wago logical device to given tango attribute.
 *
 *\param attr	related tango attribute object.
 */
void Wago::read_scalarAttrPhysValue(Tango::Attribute &attr)
{
	string &attr_name = attr.get_name();

	DEBUG_STREAM << "Wago::read_scalarAttrPhysValue  - " << device_name << endl;
	DEBUG_STREAM << "for attribute " << attr_name << endl;

	unsigned short key;
	vector<float> read_value;

	scallarAttribBuf_t *bptr = &scallarAttributeValues[attr_name];
	wd->ReadPhys(bptr->key, read_value);
	bptr->value = read_value[0];

	// apply the read value
	attr.set_value (&bptr->value);
}

/*! Method writes the value of Tango attribute to related wago logical device.
 *
 * \param attr	related Tango attribute object.
 */
void Wago::write_scalarAttrPhysValue(Tango::WAttribute &attr)
{
	INFO_STREAM << "Wago::write_scalarAttrPhysValue  - " << device_name << endl;

	unsigned short key;
	string attr_name = attr.get_name();
	wd->Name2Key(attr_name,key);

	float w_value;
	attr.get_write_value(w_value);

	vector<float> write_vect(2);
	write_vect[0] = 0;
	write_vect[1] = w_value;
	wd->WritePhys(key, write_vect);

}

/* ! Check if operation on scallar attribute is allowed. Not used.
 *
 */
bool Wago::is_scalarAttrPhysValue_allowed(Tango::AttReqType ty)
{
	return true; //TODO add state handling
}

/*! Method writes value of related wago logical device to given tango attribute.
 *	This method if for spectrum attributes.
 *
 * \param attr	related Tango attribute object.
 */
void Wago::read_spectAttrPhysValue(Tango::Attribute &att)
{
	string &attr_name = att.get_name();

	DEBUG_STREAM << "Wago::read_spectAttrPhysValue  - " << device_name << endl;
	DEBUG_STREAM << "for attribute " << attr_name << endl;

	spectrumAttribBuf_t *bptr = &spectrumAtributeValues[attr_name];
	bptr->values.clear();
	wd->ReadPhys(bptr->key, bptr->values);

	// apply the read value
#if (__cplusplus > 199711L) || defined(HACK_GCC_ITS_CPP0X)
	att.set_value (bptr->values.data(), bptr->values.size());
#else
	att.set_value (&bptr->values[0], bptr->values.size());
#endif
}

/*! Method writes the value of Tango attribute to related wago logical device.
 *	This method if for spectrum attributes.
 *
 * \param attr	related Tango attribute object.
 */
void Wago::write_spectAttrPhysValue(Tango::WAttribute &att)
{
	INFO_STREAM << "Wago::write_spectAttrPhysValue  - " << device_name << endl;

	unsigned short key;
	string attr_name = att.get_name();
	wd->Name2Key(attr_name,key);

	const float* w_value;
	unsigned int writeVal_length;
	vector<float> w_valueBuff;
	att.get_write_value(w_value);
	writeVal_length = att.get_write_value_length();

	w_valueBuff.resize(writeVal_length*2);
	unsigned int i,j;
	for(i = 0, j = 0; i < writeVal_length ; i++, j += 2)
	{
		w_valueBuff[j] = i;
		w_valueBuff[j+1] = w_value[i];
	}


	wd->WritePhys(key, w_valueBuff);

}

/*! Check if operation on scallar attribute is allowed. Not used.
 *
 */
bool Wago::is_spectAttrPhysValue_allowed(Tango::AttReqType ty)
{
	return true;
}

/*----- PROTECTED REGION END -----*/	//	Wago::namespace_ending
} //	namespace
