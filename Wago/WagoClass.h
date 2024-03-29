/*----- PROTECTED REGION ID(WagoClass.h) ENABLED START -----*/
//=============================================================================
//
// file :        WagoClass.h
//
// description : Include for the Wago root class.
//               This class is the singleton class for
//                the Wago device class.
//               It contains all properties and methods which the 
//               Wago requires only once e.g. the commands.
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
// $Author: ohlsson $
//
// $Revision: 1.6 $
// $Date: 2017/01/04 15:54:08 $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef WagoClass_H
#define WagoClass_H

#include <tango.h>
#include <Wago.h>


/*----- PROTECTED REGION END -----*/	//	WagoClass.h


namespace Wago_ns
{
/*----- PROTECTED REGION ID(WagoClass::classes for dynamic creation) ENABLED START -----*/


/*----- PROTECTED REGION END -----*/	//	WagoClass::classes for dynamic creation

//=========================================
//	Define classes for commands
//=========================================
//	Command DevReadNoCachePhys class definition
class DevReadNoCachePhysClass : public Tango::Command
{
public:
	DevReadNoCachePhysClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(cmd_name,in,out,in_desc,out_desc, level)	{};

	DevReadNoCachePhysClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(cmd_name,in,out)	{};
	~DevReadNoCachePhysClass() {};

	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Wago *>(dev))->is_DevReadNoCachePhys_allowed(any);}
};

//	Command DevWritePhys class definition
class DevWritePhysClass : public Tango::Command
{
public:
	DevWritePhysClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(cmd_name,in,out,in_desc,out_desc, level)	{};

	DevWritePhysClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(cmd_name,in,out)	{};
	~DevWritePhysClass() {};

	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Wago *>(dev))->is_DevWritePhys_allowed(any);}
};

//	Command DevReadPhys class definition
class DevReadPhysClass : public Tango::Command
{
public:
	DevReadPhysClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(cmd_name,in,out,in_desc,out_desc, level)	{};

	DevReadPhysClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(cmd_name,in,out)	{};
	~DevReadPhysClass() {};

	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Wago *>(dev))->is_DevReadPhys_allowed(any);}
};

//	Command DevWriteDigi class definition
class DevWriteDigiClass : public Tango::Command
{
public:
	DevWriteDigiClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(cmd_name,in,out,in_desc,out_desc, level)	{};

	DevWriteDigiClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(cmd_name,in,out)	{};
	~DevWriteDigiClass() {};

	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Wago *>(dev))->is_DevWriteDigi_allowed(any);}
};

//	Command DevReadDigi class definition
class DevReadDigiClass : public Tango::Command
{
public:
	DevReadDigiClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(cmd_name,in,out,in_desc,out_desc, level)	{};

	DevReadDigiClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(cmd_name,in,out)	{};
	~DevReadDigiClass() {};

	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Wago *>(dev))->is_DevReadDigi_allowed(any);}
};

//	Command DevReadNoCacheDigi class definition
class DevReadNoCacheDigiClass : public Tango::Command
{
public:
	DevReadNoCacheDigiClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(cmd_name,in,out,in_desc,out_desc, level)	{};

	DevReadNoCacheDigiClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(cmd_name,in,out)	{};
	~DevReadNoCacheDigiClass() {};

	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Wago *>(dev))->is_DevReadNoCacheDigi_allowed(any);}
};

//	Command DevGetKeys class definition
class DevGetKeysClass : public Tango::Command
{
public:
	DevGetKeysClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(cmd_name,in,out,in_desc,out_desc, level)	{};

	DevGetKeysClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(cmd_name,in,out)	{};
	~DevGetKeysClass() {};

	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Wago *>(dev))->is_DevGetKeys_allowed(any);}
};

//	Command DevKey2Name class definition
class DevKey2NameClass : public Tango::Command
{
public:
	DevKey2NameClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(cmd_name,in,out,in_desc,out_desc, level)	{};

	DevKey2NameClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(cmd_name,in,out)	{};
	~DevKey2NameClass() {};

	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Wago *>(dev))->is_DevKey2Name_allowed(any);}
};

//	Command DevLog2Hard class definition
class DevLog2HardClass : public Tango::Command
{
public:
	DevLog2HardClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(cmd_name,in,out,in_desc,out_desc, level)	{};

	DevLog2HardClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(cmd_name,in,out)	{};
	~DevLog2HardClass() {};

	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Wago *>(dev))->is_DevLog2Hard_allowed(any);}
};

//	Command DevHard2Log class definition
class DevHard2LogClass : public Tango::Command
{
public:
	DevHard2LogClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(cmd_name,in,out,in_desc,out_desc, level)	{};

	DevHard2LogClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(cmd_name,in,out)	{};
	~DevHard2LogClass() {};

	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Wago *>(dev))->is_DevHard2Log_allowed(any);}
};

//	Command DevName2Key class definition
class DevName2KeyClass : public Tango::Command
{
public:
	DevName2KeyClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(cmd_name,in,out,in_desc,out_desc, level)	{};

	DevName2KeyClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(cmd_name,in,out)	{};
	~DevName2KeyClass() {};

	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Wago *>(dev))->is_DevName2Key_allowed(any);}
};

//	Command DevWcComm class definition
class DevWcCommClass : public Tango::Command
{
public:
	DevWcCommClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(cmd_name,in,out,in_desc,out_desc, level)	{};

	DevWcCommClass(const char   *cmd_name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(cmd_name,in,out)	{};
	~DevWcCommClass() {};

	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Wago *>(dev))->is_DevWcComm_allowed(any);}
};


/**
 *	The WagoClass singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  WagoClass : public Tango::DeviceClass
#else
class WagoClass : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(WagoClass::Additional DServer data members) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	WagoClass::Additional DServer data members

	public:
		//	Class properties data members
		//	modulesCatalogue:	List of know WAGO modules usable by the WAGO Device Server
		//  SYNTAX: 
		//     -the first item should be the date the list has been updated
		//     -then, for each module, you must supply:
		//            -module reference
		//            -number of digital  inputs
		//            -number of digital outputs
		//            -number of word     inputs
		//            -number of word    outputs
		//            -number of logical channels (typically SSI32bits==2 words)
		//            -string for special module  (``none``,``ssi``,``thc``,``thc100``,``thck``,etc)
		//            -string for description
		//  
		//  example:
		//  
		//  750-400,    2, 0, 0, 0, 2, ``none``,      ``2 Channel Digital Input``
		//  750-401,    2, 0, 0, 0, 2, ``none``,      ``2 Channel Digital Input``
		//  750-402,    4, 0, 0, 0, 4, ``none``,      ``4 Channel Digital Input``
		//  750-403,    4, 0, 0, 0, 4, ``none``,      ``4 Channel Digital Input``
		//  750-404,    0, 0, 3, 0, 3, ``none``,      ``32 bit Counter``
		//  750-405,    2, 0, 0, 0, 2, ``none``,      ``2 Channel Digital Input``
		//  750-406,    2, 0, 0, 0, 2, ``none``,      ``2 Channel Digital Input``
		//  750-408,    4, 0, 0, 0, 4, ``none``,      ``4 Channel Digital Input``
		//  750-409,    4, 0, 0, 0, 4, ``none``,      ``4 Channel Digital Input``
		//  750-410,    2, 0, 0, 0, 2, ``none``,      ``2 Channel Digital Input``
		//  750-411,    2, 0, 0, 0, 2, ``none``,      ``2 Channel Digital Input``
		//  750-412,    2, 0, 0, 0, 2, ``none``,      ``2 Channel Digital Input``
		//  750-414,    4, 0, 0, 0, 4, ``none``,      ``4 Channel Digital Input``
		//  750-415,    4, 0, 0, 0, 4, ``none``,      ``4 Channel Digital Input``
		//  750-422,    4, 0, 0, 0, 4, ``none``,      ``4 Channel Digital Input``
		//  750-432,    4, 0, 0, 0, 4, ``none``,      ``4 Channel Digital Input``
		//  750-9999/400-004,    4, 0, 0, 0, 4, ``none``,      ``4 Channel Digital Input``
		//  750-430,    8, 0, 0, 0, 8, ``none``,      ``8 Channel Digital Input``
		//  750-436,    8, 0, 0, 0, 8, ``none``,      ``8 Channel Digital Input``
		//  750-485,    0, 0, 2, 0, 2, ``fs4-20_13``, ``2 Channel 4/20mA Input``
		//  750-501,    0, 2, 0, 0, 2, ``none``,      ``2 Channel Digital Output``
		//  750-502,    0, 2, 0, 0, 2, ``none``,      ``2 Channel Digital Output``
		//  750-504,    0, 4, 0, 0, 4, ``none``,      ``4 Channel Digital Output``
		//  750-9999/500-004,    0, 4, 0, 0, 4, ``none``,      ``4 Channel Digital Output``
		//  750-506,    2, 2, 0, 0, 2, ``none``,      ``2 Channel Digital Output``
		//  750-507,    2, 2, 0, 0, 2, ``none``,      ``2 Channel Digital Output``
		//  750-508,    2, 2, 0, 0, 2, ``none``,      ``2 Channel Digital Output``
		//  750-509,    0, 2, 0, 0, 2, ``none``,      ``2 Channel Digital Output``
		//  750-512,    0, 2, 0, 0, 2, ``none``,      ``2 Normally Open Relay Output``
		//  750-513,    0, 2, 0, 0, 2, ``none``,      ``2 Normally Open Relay Output``
		//  750-514,    0, 2, 0, 0, 2, ``none``,      ``2 Changeover Relay Output``
		//  750-516,    0, 4, 0, 0, 4, ``none``,      ``4 Channel Digital Output``
		//  750-517,    0, 2, 0, 0, 2, ``none``,      ``2 Changeover Relay Output``
		//  750-519,    0, 4, 0, 0, 4, ``none``,      ``4 Channel Digital Output``
		//  750-530,    0, 8, 0, 0, 8, ``none``,      ``8 Channel Digital Output``
		//  750-531,    0, 4, 0, 0, 4, ``none``,      ``4 Channel Digital Output``
		//  750-536,    0, 8, 0, 0, 8, ``none``,      ``8 Channel Digital Output``
		//  750-452,    0, 0, 2, 0, 2, ``fs20_13``,   ``2 Channel 0/20mA Input``
		//  750-454,    0, 0, 2, 0, 2, ``fs4-20_13``, ``2 Channel 4/20mA Input``
		//  750-461,    0, 0, 2, 0, 2, ``thc``,       ``2 Channel PT100 Input``
		//  750-462,    0, 0, 2, 0, 2, ``thc``,       ``2 Channel Thermocouple Input``
		std::vector<std::string>	modulesCatalogue;
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
		//	Method prototypes
		static WagoClass *init(const char *);
		static WagoClass *instance();
		~WagoClass();
		Tango::DbDatum	get_class_property(std::string &);
		Tango::DbDatum	get_default_device_property(std::string &);
		Tango::DbDatum	get_default_class_property(std::string &);

	protected:
		WagoClass(std::string &);
		static WagoClass *_instance;
		void command_factory();
		void attribute_factory(std::vector<Tango::Attr *> &);
		void pipe_factory();
		void write_class_property();
		void set_default_property();
		void get_class_property();
		std::string get_cvstag();
		std::string get_cvsroot();

	private:
		void device_factory(TANGO_UNUSED(const Tango::DevVarStringArray *));
		void create_static_attribute_list(std::vector<Tango::Attr *> &);
		void erase_dynamic_attributes(const Tango::DevVarStringArray *,std::vector<Tango::Attr *> &);
		std::vector<std::string>	defaultAttList;
		Tango::Attr *get_attr_object_by_name(std::vector<Tango::Attr *> &att_list, std::string attname);
};

}	//	End of namespace

#endif   //	Wago_H
