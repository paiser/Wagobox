static const char *RcsId = "$Id: ModbusConn.cpp,v 1.7 2014/03/28 10:42:35 perez Exp $";
/*
 * ModbusConn.cpp
 *
 *  Created on: Feb 14, 2013
 *      Author: kowalisz
 */

#include "ModbusConn.h"


/*!The default constructor.
 *
 * \param wagoInstance	pointer to corresponding wago device object.
 */
DeviceState::DeviceState(Tango::DeviceImpl* wagoInstance):
LogAdapter(wagoInstance)
{
}

/*!Set the state.
 *
 * \param st	state to be set.
 */
void DeviceState::SetState(Tango::DevState st)
{
	accessMutex.lock();
	state = st;
	accessMutex.unlock();
}

/*!Get state value.
 *
 * \return	state value.
 */
Tango::DevState DeviceState::GetState()
{
	Tango::DevState out;
	accessMutex.lock();
	out = state;
	accessMutex.unlock();
	return out;
}

/*!Get last exception.
 *
 * \return	last catched exception.
 */
Tango::DevFailed DeviceState::getLastException()
{
	Tango::DevFailed out;
	accessMutex.lock();
	out =  lastException;
	accessMutex.unlock();
	return out;
}

/*!Set last exception value.
 *
 * \param lastEx	exception object to be copied.
 */
void DeviceState::setLastException(Tango::DevFailed lastEx)
{
	accessMutex.lock();
	lastException = lastEx;
	INFO_STREAM << "setLastException setting last exception" << endl;
	accessMutex.unlock();
}

/*!The default constructor.
 *
 * \param mb_obj		pointer to interface object to Tango Modbus server.
 * \param wagoInstance	pointer to corresponding wago device object.
 * \param devSt			pointer to device state holder object.
 */
ModbusConn::ModbusConn(Tango::DeviceProxy* mb_obj, Tango::DeviceImpl* wagoInstance, DeviceState* devSt):
LogAdapter(wagoInstance),
modbus_obj(mb_obj),
devState(devSt)
{
}

/*!Implementation of ReadDigitalInputs using tango Modbus class (See ModbusAbstract class).
 *
 */
int ModbusConn::ReadDigitalInputs(unsigned int addr, unsigned int numOfInputs, vector<unsigned short>& dataBuffer)
{
 	vector<unsigned char> data;
	Tango::DevVarShortArray inArgs;
	inArgs.length(2);
	inArgs[0] = addr;
	inArgs[1] = numOfInputs;
	Tango::DeviceData indat, outdat;
	indat << inArgs;
	try{
		outdat = modbus_obj->command_inout("ReadInputStatus", indat);
	}catch(Tango::DevFailed &ex)
	{
		ERROR_STREAM << "ModbusConn::ReadDigitalInputs catched exception" << endl;
		devState->setLastException(ex);
		throw ex;
	}
	outdat >> data;
	dataBuffer.resize(data.size());
	copy(data.begin(),data.end(), dataBuffer.begin());
	return 0;
}

/*!Implementation of ReadInputRegisters using tango Modbus class (See ModbusAbstract class).
 *
 */
int ModbusConn::ReadInputRegisters(unsigned int addr, unsigned int numOfRegisters, vector<unsigned short>& dataBuffer)
{
	//vector<short> data;
	Tango::DevVarShortArray inArgs;
	inArgs.length(2);
	inArgs[0] = addr;
	inArgs[1] = numOfRegisters;
	Tango::DeviceData indat,outdat;
	indat << inArgs;
	try{
		outdat = modbus_obj->command_inout("ReadInputRegisters", indat);
	}catch(Tango::DevFailed &ex)
	{
		ERROR_STREAM << "ModbusConn::ReadInputRegisters catched exception" << endl;
		devState->setLastException(ex);
		throw ex;
	}
	outdat >> (vector<short>&)dataBuffer;
	return 0;
}

/*!Implementation of ReadHoldingRegisters using tango Modbus class (See ModbusAbstract class).
 *
 */
int ModbusConn::ReadHoldingRegisters(unsigned int addr, unsigned int numOfRegisters, vector<unsigned short>& dataBuffer)
{
	Tango::DevVarShortArray inArgs;
	inArgs.length(2);
	inArgs[0] = addr;
	inArgs[1] = numOfRegisters;
	Tango::DeviceData indat,outdat;
	indat << inArgs;
	try{
		outdat = modbus_obj->command_inout("ReadHoldingRegisters", indat);
	}catch(Tango::DevFailed &ex)
	{
		ERROR_STREAM << "ModbusConn::ReadHoldingRegisters catched exception" << endl;
		devState->setLastException(ex);
		throw ex;
	}

	outdat >> (vector<short>&)dataBuffer;
	return 0;
}

/*!Implementation of ReadMultipleCoilsStatus using tango Modbus class (See ModbusAbstract class).
 *
 */
int ModbusConn::ReadMultipleCoilsStatus(unsigned int addr,unsigned int numOfCoils, vector<unsigned short>& dataBuffer)
{
	Tango::DevVarShortArray inArgs;
	inArgs.length(2);
	inArgs[0] = addr;
	inArgs[1] = numOfCoils;
	Tango::DeviceData indat,outdat;
	indat << inArgs;
	try{
		outdat = modbus_obj->command_inout("ReadMultipleCoilsStatus", indat);
	}catch(Tango::DevFailed &ex)
	{
		ERROR_STREAM << "ModbusConn::ReadMultipleCoilsStatus catched exception" << endl;
		devState->setLastException(ex);
		throw ex;
	}

	outdat >> (vector<short>&)dataBuffer;
	return 0;
}

/*!Implementation of ForceMultipleCoils using tango Modbus class (See ModbusAbstract class).
 *
 */
void ModbusConn::ForceMultipleCoils(unsigned int addr, vector<unsigned short>& values)
{
	Tango::DevVarShortArray inArgs;
	inArgs.length(2+values.size());
	inArgs[0] = (unsigned short)addr;
	inArgs[1] = (unsigned short)values.size();

	for(unsigned int i = 0; i < values.size(); i++)
		inArgs[i+2] = values[i];

	Tango::DeviceData indat;
	indat << inArgs;
	try{
		modbus_obj->command_inout("ForceMultipleCoils", indat);
	}catch(Tango::DevFailed &ex)
	{
		ERROR_STREAM << "ModbusConn::ForceMultipleCoils catched exception" << endl;
		devState->setLastException(ex);
		throw ex;
	}

}

/*!Implementation of PresetSingleRegister using tango Modbus class (See ModbusAbstract class).
 *
 */
void ModbusConn::PresetSingleRegister(unsigned int addr, unsigned short value)
{
	Tango::DevVarShortArray inArgs;
	inArgs.length(2);

	inArgs[0] = (unsigned short)addr;
	inArgs[1] = (unsigned short)value;

	Tango::DeviceData indat;
	indat << inArgs;
	try{
		modbus_obj->command_inout("PresetSingleRegister", indat);
	}catch(Tango::DevFailed &ex)
	{
		ERROR_STREAM << "ModbusConn::PresetSingleRegister catched exception" << endl;
		devState->setLastException(ex);
		throw ex;
	}
}

/*!Implementation of ForceMultipleCoils using tango Modbus class (See ModbusAbstract class).
 *
 */
void ModbusConn::PresetMultipleRegisters(unsigned int addr, vector<unsigned short>& values)
{
	Tango::DevVarShortArray inArgs;
	inArgs.length(2+values.size());
	inArgs[0] = (unsigned short)addr;
	inArgs[1] = (unsigned short)values.size();

	for(unsigned int i = 0; i < values.size(); i++)
			inArgs[i+2] = values[i];

	Tango::DeviceData indat;
	indat << inArgs;
	try{
		modbus_obj->command_inout("PresetMultipleRegisters", indat);
	}catch(Tango::DevFailed &ex)
	{
		ERROR_STREAM << "ModbusConn::PresetMultipleRegisters catched exception" << endl;
		devState->setLastException(ex);
		throw ex;
	}
}

/*!Implementation of ModbusStateCheck from ModbusAbstract class.
 *
 */
bool ModbusConn::ModbusStateCheck()
{
	try
	{
		Tango::DeviceData indat = modbus_obj->command_inout("State");
//		cout << "ModbusStateCheck state valid"<< endl;
//		devState->SetState(Tango::ON);		//TODO this is temporary since states is not implemented in Modbus Server
		return false;
	}catch(Tango::DevFailed &ex )
	{
		ERROR_STREAM << "ModbusStateCheck state not valid"<< endl;
		devState->SetState(Tango::FAULT);
		devState->setLastException(ex);
		return true;
	}
}

/*!Implementation of RaiseLastModbusException from ModbusAbstract class.
 *
 */
void ModbusConn::RaiseLastModbusException()
{
	throw this->devState->getLastException();
}


/*!Implementation of InconsistentImageFault from ModbusAbstract class.
 *
 */
void ModbusConn::InconsistentImageFault(std::string desc)
{
	devState->SetState(Tango::FAULT);
	try{
		Tango::Except::throw_exception("ModbusConn::InconsistentImageFault","Modbus process image inconsistency detected", desc);
	}catch(Tango::DevFailed &ex)
	{
		devState->setLastException(ex);
	}
}

/*!Implementation of ImageConsistent from ModbusAbstract class.
 *
 */
void ModbusConn::ImageConsistent()
{
	devState->SetState(Tango::ON);
}

/*!Implementation of LockAccess from ModbusAbstract class.
 *
 */
void ModbusConn::LockAccess()
{
	modbusAccessMutex.lock();
}

/*!Implementation of UnlockAccess from ModbusAbstract class.
 *
 */
void ModbusConn::UnlockAccess()
{
	modbusAccessMutex.unlock();
}

