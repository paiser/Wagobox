/*
 * ModbusConn.h
 *
 *  Created on: Feb 14, 2013
 *      Author: kowalisz
 */

#ifndef MODBUSCONN_H_
#define MODBUSCONN_H_

#include <tango.h>
#include "./core_src/ModbusAbstract.h"

/*!Class holding device state and last catched exception.
 *
 */
class DeviceState:public Tango::LogAdapter
{
public:
	DeviceState(Tango::DeviceImpl* wagoInstance);
	void SetState(Tango::DevState st);
	Tango::DevState GetState();
	Tango::DevFailed getLastException();
	void setLastException(Tango::DevFailed lastEx);
private:
	omni_mutex accessMutex; //!Protection for access from different threads.
	Tango::DevState state; //!A place holder for current device state.
	Tango::DevFailed lastException;//!A place holder for last catched exception.

};


/*!This class is implementation of Modbus protocol interface using Tango Modbus class.
 *
 */
class ModbusConn: public ModbusAbstract, public Tango::LogAdapter
{
public:
	ModbusConn(Tango::DeviceProxy* modbus_obj, Tango::DeviceImpl* wagoInstance, DeviceState* devSt);

	virtual int ReadDigitalInputs(unsigned int addr, unsigned int numOfInputs, vector<unsigned short>& dataBuffer);
	virtual int ReadInputRegisters(unsigned int addr, unsigned int numOfRegisters, vector<unsigned short>& dataBuffer);
	virtual int ReadHoldingRegisters(unsigned int addr, unsigned int numOfRegisters, vector<unsigned short>& dataBuffer);
	virtual int ReadMultipleCoilsStatus(unsigned int addr,unsigned int numOfCoils, vector<unsigned short>& dataBuffer);
	virtual int ForceMultipleCoils(unsigned int addr, vector<unsigned short>& values);
	virtual int PresetSingleRegister(unsigned int addr, unsigned short value);
	virtual int PresetMultipleRegisters(unsigned int addr, vector<unsigned short>& values);
	virtual bool ModbusStateCheck();
	virtual void RaiseLastModbusException();
	virtual void InconsistentImageFault(std::string desc);
	virtual void ImageConsistent();

	virtual void LockAccess();
	virtual void UnlockAccess();
private:
	omni_mutex modbusAccessMutex; //!Protection for access from different threads.
	DeviceState *devState;	//! Pointer to device state holder.
	Tango::DeviceProxy* modbus_obj; //!Pointer to interface object for Tango Modbus server.
};


#endif /* MODBUSCONN_H_ */
