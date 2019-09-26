/*
 * Services.h
 *
 *  Created on: Apr 26, 2013
 *      Author: kowalisz
 */

#ifndef SERVICES_H_
#define SERVICES_H_

#include "WagoDevice.h"

/*!Abstract class using visitor design pattern. A base class for service classses
 *
 */
class Visitor
{
public:
	virtual int VisitLogicalDevice(LogicalDevice* ld) = 0;
	virtual int VisitModule(Module* md) = 0;
	virtual int VisitWagoDevice(WagoDevice* wd)= 0;

	LOGGING_ADDONS;
};

/*Class implementing Hard2Log service.
 *
 */
class Hard2LogService: public Visitor
{
public:
	Hard2LogService(unsigned short off, unsigned short type, vector<unsigned short>* vals);
	virtual int VisitLogicalDevice(LogicalDevice* ld);
	virtual int VisitModule(Module* md);
	virtual int VisitWagoDevice(WagoDevice* wd);

private:
	void GetAddr(BufferHolder& buffers);

	unsigned short modType; //! Type of module (input/output).
	unsigned short offset; //! Offset in process image to module memory
	Module* fModule; //! Pointer to module related to offset.
	unsigned int fChannel; //! Module channel related to offset.
	vector<unsigned short>* values; //!Pointer to buffer for service output.

	unsigned short* addr; //!Direct pointer to module memory.
};

/*Class implementing Log2Hard service.
 *
 */
class Log2HardService: public Visitor
{
public:
	Log2HardService(unsigned short ldKey, unsigned int chan, vector<unsigned short>* val);
	virtual int VisitLogicalDevice(LogicalDevice* ld);
	virtual int VisitModule(Module* md);
	virtual int VisitWagoDevice(WagoDevice* wd);

protected:
	unsigned short lDeviceKey; //!Numeric key of logical device.
	unsigned int channel; //!Channel number of logical device.
	Module* modulePtr; //!Pointer to module related to logical device channel.
	vector<unsigned short>* values; //!Pointer to buffer for service output.

};

/*Class implementing Status service.
 *
 */
class StatusService: public Visitor
{
public:
	StatusService(string* output);
	virtual int VisitLogicalDevice(LogicalDevice* ld);
	virtual int VisitModule(Module* md);
	virtual int VisitWagoDevice(WagoDevice *wagoDev);

protected:
	int ParseConfig(configInfo &cfg);
	vector<wagoModuleDesc*> modulesSeenByDevice; //! List of physical modules read through modbus from device.
	string* out; //!Pointer to buffer for service output.
	WagoDevice* wd; //!Pointer to root wago device object (it is used by VisitLogicalDevice).

};



#define DEF_WCCOMM_PERIOD 1     /* polling sleep time in mS                */

//
// Addresses in OW memory space used for ISG protocol communication with
// the program running inside the wago controller
//
#define WC_PASSWD         256
#define WC_INCMD          257
#define WC_NPAR           258
#define WC_PAR0           259
//#define WC_NPAR_MAX       100
#define WC_NPAR_MAX       (PHYS_CACHE_ADDR-WC_PAR0)


//
// Addresses in IW memory space used for ISG protocol communication with
// the program running inside the wago controller
//
#define WC_VER            256
#define WC_ID             257
#define WC_OUTCMD         258
#define WC_NRES           259
#define WC_RES0           260
#define WC_NRES_MAX       100

#define WC_PASSWD_TAG     0xa5a5
#define WC_VER_TAG        0xaa   // MSB
#define WC_TO             1000   // unit is mS

/*! Class implementing WcComm service.
 *
 */
class WcCommService: public Visitor
{
public:
	WcCommService(vector<unsigned short> *inArgs, vector<unsigned short> *outArgs);
	virtual int VisitLogicalDevice(LogicalDevice* ld);
	virtual int VisitModule(Module* md);
	virtual int VisitWagoDevice(WagoDevice* wd);
	virtual int VisitModbusConnection(ModbusAbstract* mba);
private:
	vector<unsigned short> *inargs; //! pointer to containter holding input arguments of service.
	vector<unsigned short> *outargs; //! pointer to containter for storing output arguments of service.
};



#endif /* SERVICES_H_ */
