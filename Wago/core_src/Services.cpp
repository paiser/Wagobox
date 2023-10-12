static const char *RcsId = "$Id: Services.cpp,v 1.11 2018/01/19 12:15:04 perez Exp $";
/*
 * Services.cpp
 *
 *  Created on: Apr 26, 2013
 *      Author: kowalisz
 */


#include "Services.h"


/*!The default constructor.
 *
 * \param off requested offset.
 * \param type	type of point which is searched.
 * \param vals	pointer to containter for output of service.
 */
Hard2LogService::Hard2LogService(unsigned short off, unsigned short type, vector<unsigned short>* vals)
{
	offset=off;
	values=vals;
	modType=type;
	fModule = NULL;
	fChannel = 0;
	values->resize(2);
}

/*!Method excecutes service actions related to Logical device object
 *
 * \param ld	pointer to logical device object.
 */
int Hard2LogService::VisitLogicalDevice(LogicalDevice* ld)
{

	unsigned int i = 0;
	logDeviceValueMapping* lm = NULL;

	while(lm =ld->GetChannel(i))
	{
		if((lm->module == fModule) && (lm->channel == fChannel))
		{
			(*values)[1] = i;
			return 0;
		}
		i++;
	}

	return -1;
}

/*!Method excecutes service actions related to module object.
 *
 * \param md	pointer to module object.
 *
 * \return number of channel related to addres or -1 on error.
 */
int Hard2LogService::VisitModule(Module* md)
{
	wagoModuleDesc* dsc =  md->GetModuleDescriptor();
	for(unsigned int i = 0 ; i < dsc->channels; i++)
	{
		if(md->IsWithinAddresRange(addr, i))
			return i;
	}

	return -1;
}

/*!Method excecutes service actions related to wago device object.
 *
 * \param wd	pointer to wago device object.
 */
void Hard2LogService::VisitWagoDevice(WagoDevice* wd)
{
	Module* md;
	LogicalDevice *ld;

	GetAddr(wd->buffers);

	unsigned int i = 0;
	while(md = wd->GetModule(i))
	{
		int ret = VisitModule(md);
		if( ret != -1)
		{
			fChannel = (unsigned int)ret;
			fModule = md;
			break;
		}
		i++;
	}

	if(!md)
	{
		ERROR_STREAM << "Hard2LogService::VisitWagoDevice() invalid given offset argument." << endl;
		EXCEPTION_RETURN("Hard2LogService::VisitWagoDevice","invalid offset", "Modbus::error_read");
	}

	i = 0;
	while(ld = wd->GetLd(i))
	{
		if(!VisitLogicalDevice(ld))
		{
			(*values)[0] = i;
			break;
		}
		i++;
	}

	if(!ld)
	{
		ERROR_STREAM << "Hard2LogService::VisitWagoDevice() Could not locate Logical Device for given offset" << endl;
		EXCEPTION_RETURN("Hard2LogService::VisitWagoDevice","Could not locate Logical Device for given offset", "Modbus::error_read");
	}

}

/*!Get the address of the buffer and number of registers according to searched register type.
 *
 * \param buffers	reference to buffer holder object.
 */
void Hard2LogService::GetAddr(BufferHolder& buffers)
{
	unsigned short* base;
	unsigned int num;

	switch(modType)
	{
	case BINARY_INPUT:
		base = buffers.GetDigitalInputsBuffAddr();
		num = buffers.GetNumOfDigitalInputs();
		break;

	case REGISTER_INPUT:
		base = buffers.GetInputRegistersBuffAddr();
		num = buffers.GetNumOfInputRegisters();
		break;

	case BINARY_OUTPUT:
		base = buffers.GetCoilsBuffAddr();
		num = buffers.GetNumOfCoils();
		break;

	case REGISTER_OUTPUT:
		base = buffers.GetHoldingRegistersBuffAddr();
		num = buffers.GetNumOfHoldingRegisters();
		break;
	 default:
		ERROR_STREAM << "Hard2LogService::GetAddr() wrong I/O type given." << endl;
		EXCEPTION_RETURN("Hard2LogService::GetAddr","wrong I/O type (ex: ('I'<<8)+'W')", "Modbus::error_read");

	}

	if(offset > num)
	{
		ERROR_STREAM << "Hard2LogService::GetAddr() invalid offset given." << endl;
		EXCEPTION_RETURN("WagoDevice::Key2Name","invalid offset", "Modbus::error_read");
	}

	addr = base + offset;
}

/*!The default constructor.
 *
 * \param ldKey key of requested logicall device.
 * \param chan	requested channel of logicall device.
 * \param val	pointer to containter for output of service.
 */
Log2HardService::Log2HardService(unsigned short ldKey, unsigned int chan, vector<unsigned short>* val)
{
	channel=chan;
	values=val;
	values->resize(5);
	lDeviceKey = ldKey;
}

/*!Method excecutes service actions related to Logical device object
 *
 * \param ld	pointer to logical device object.
 */
int Log2HardService::VisitLogicalDevice(LogicalDevice* ld)
{
	logDeviceValueMapping* lChan = ld->GetChannel(channel);
	if(!lChan)
	{
		ERROR_STREAM << "Log2HardService::VisitLogicalDevice() invalid logical channel Key" << endl;
		EXCEPTION_RETURN("WagoDevice::Key2Name","invalid logical channel Key", "Modbus::error_read");
	}

	modulePtr = lChan->module;
	(*values)[4] = lChan->channel;
	VisitModule(modulePtr);

	return 0;
}

/*!Method excecutes service actions related to module object.
 *
 * \param md	pointer to module object.
 */
int Log2HardService::VisitModule(Module* md)
{
	wagoModuleDesc* mDesc = md->GetModuleDescriptor();
	(*values)[1]= mDesc->mtype;

	if((mDesc->mtype & 0xff00) == OUTPUT)
		(*values)[0] = md->GetOutputOffset((*values)[4]);
	else
		(*values)[0] = md->GetInputOffset((*values)[4]);

	DEBUG_STREAM << "Log2HardService::VisitModule() module offset = 0x" << std::hex << (*values)[0] << std::dec << endl;
	vector<string> tmp = string2vector(mDesc->name,"-");
	if(tmp.size() >=2)
	{
		istringstream iss(tmp[1]);
		iss >> (*values)[2];
	}

	return 0;
}

/*!Method excecutes service actions related to wago device object.
 *
 * \param wd	pointer to wago device object.
 */
void Log2HardService::VisitWagoDevice(WagoDevice* wd)
{

	LogicalDevice* ld = wd->GetLd(lDeviceKey);

	if(!ld)
	{
		ERROR_STREAM << "Log2HardService::VisitWagoDevice() invalid device Key" << endl;
		EXCEPTION_RETURN("WagoDevice::Key2Name","invalid device Key", "Modbus::error_read");
	}

	VisitLogicalDevice(ld);

	(*values)[3] = wd->GetModuleIndex(modulePtr);
}

/*!The default constructor.
 *
 * \param output pointer to containter for service output.
 */
StatusService::StatusService(string* output):
out(output)
{
}

/*!Process given configuration, form the status report as string and store it in output containter.
 *
 * \param cfg	configuration for processing.
 */
int StatusService::ParseConfig(configInfo &cfg)
{
	stringstream ss;

	//TODO coupler/controller check
	ss << "Controller series code       (INFO_SERIES)  : " << cfg.seriesCode << endl;
	ss << "Controller order number      (INFO_ITEM)    : " << cfg.couplerControllerCode << endl;
	ss << "Controller firmware revision (INFO_REVISION): " << cfg.firmwareVer << endl;
	ss << "Controller date of firmware  (INFO_DATE)    : ";
	for(unsigned int i = 0; i < FIRMWARE_DATE_TIME_BUFFER_SIZE; i++)
	{
		char c = (char)(cfg.firmwareDate[i] & 0xff);

		if (c < 32)
			c = ' ';
		ss << c;
		c = (char) ((cfg.firmwareDate[i] >> 8) & 0xff);
		if (c < 32)
			c = ' ';
		ss << c;
	}
	ss << endl;

	ss << "time of firmware  (INFO_TIME)    : ";
	for(unsigned int i = 0; i < FIRMWARE_DATE_TIME_BUFFER_SIZE; i++)
	{
		char c = (char)(cfg.firmwareTime[i] & 0xff);

		if (c < 32)
			c = ' ';
		ss << c;
		c = (char) ((cfg.firmwareTime[i] >> 8) & 0xff);
		if (c < 32)
			c = ' ';
		ss << c;
	}
	ss << endl;

	//TODO firmware version check

	ss << "Wago modules physically plugged and seen by the controller:" << endl;
	for(unsigned int i = 0; i < cfg.modules.size(); i++)
	{
		if(!cfg.modules[i])
			break;

		ss  << "module" << i << ":  ";
		if(cfg.modules[i] & 0x8000)
			ss << "I/O mod" << endl;
		else
		{
			ostringstream oss;
			oss << "750-" << cfg.modules[i];

			wagoModuleDesc* dsc;
			try{
				dsc = ModuleDB::Instance()->FindModule(oss.str());
			}catch(...)
			{
				dsc = NULL;
			}

			ss << cfg.seriesCode << "- " << cfg.modules[i];
			if(dsc)
				ss << " " << "(" << dsc->description << ")";
			ss << endl;

			oss.str("");
		}
	}


	out->append(ss.str());

	return 0;
}

/*!Method excecutes service actions related to module object.
 * In this service this method is not used returns 0.
 *
 * \param md	pointer to module object.
 */
int StatusService::VisitModule(Module* md)
{
	return 0;
}

/*!Method excecutes service actions related to Logical device object
 *
 * \param ld	pointer to logical device object.
 */
int StatusService::VisitLogicalDevice(LogicalDevice* ld)
{
	stringstream ss;

	ss << ld->GetName() << ":" << endl;

	logDeviceValueMapping *map = NULL;
	unsigned int i = 0;
	for( ;map = ld->GetChannel(i); i++)
	{
		ss << "logical_channel" << i << ":" << "  ";


		int modNum = wd->GetModuleIndex(map->module);
		if(!(modNum < 0) )
			ss << "module: " <<	modNum << "  ";


		ss << "channel: " << map->channel << endl;
	}

	out->append(ss.str());
	return 0;
}

/*!Method excecutes service actions related to wago device object.
 *
 * \param wd	pointer to wago device object.
 */
void StatusService::VisitWagoDevice(WagoDevice *wagoDev)
{
	configInfo cfg;
	this->wd = wagoDev;
	wd->buffers.ReadLock();
	wd->buffers.GetConfigInformation(cfg);
	wd->buffers.ReadUnlock();

	ParseConfig(cfg);


	stringstream ss;
	ss << "Wago modules known by the device server:" << endl;


	Module *mod = NULL;
	unsigned int i = 0;
	for(; mod = wd->GetModule(i); i++)
	{
		ss  << "module" << i << ":  ";
		wagoModuleDesc *dsc = mod->GetModuleDescriptor();
		ss << dsc->name << "  (" << dsc->description << ") ";

		LogicalDevice* ld=NULL;
		for(unsigned int j = 0; ld = wd->GetLd(j); j++)
		{
			logDeviceValueMapping* lmp=NULL;
			for(unsigned int k = 0; lmp = ld->GetChannel(k); k++)
			{
				if(lmp->module == mod)
					ss << ld->GetName() << " ";
			}

		}
		ss << endl;
	}

	ss << "List of logical devices:" << endl;

	out->append(ss.str());

	LogicalDevice *ld = NULL;
	for(i = 0; ld = wd->GetLd(i); i++)
	{
		VisitLogicalDevice(ld);
	}
}

/*!The default constructor.
 *
 * \param inArgu	pointer to containter with input arguments.
 * \param outArgs pointer to containter for service output.
 */
WcCommService::WcCommService(vector<unsigned short> *inArgs, vector<unsigned short> *outArgs):
inargs(inArgs),
outargs(outArgs)
{
}

/*!Method excecutes service actions related to Logical device object
 * In this service this method is not used returns 0.
 *
 * \param ld	pointer to logical device object.
 */
int WcCommService::VisitLogicalDevice(LogicalDevice* ld)
{
	return 0;
}

/*!Method excecutes service actions related to module object.
 * In this service this method is not used returns 0.
 *
 * \param md	pointer to module object.
 */
int WcCommService::VisitModule(Module* md)
{
	return 0;
}

/*!Method excecutes service actions related to wago device object.
 *
 * \param wd	pointer to wago device object.
 */
void WcCommService::VisitWagoDevice(WagoDevice* wd)
{
	ModbusAbstract* mbDev = wd->buffers.getModbusInterface();


	mbDev->LockAccess();
	try{
		VisitModbusConnection(mbDev);
	}catch(...)
	{
		ERROR_STREAM << "WcCommService::VisitWagoDevice() catched exception while service" << endl;
		mbDev->UnlockAccess();
		throw;
	}
	mbDev->UnlockAccess();
}

/*!Method executes service transactions with remote device.
 *
 * \param mba	pointer to modbus communication object.
 */
void WcCommService::VisitModbusConnection(ModbusAbstract* mba)
{
	vector<unsigned short> outbuff;
	vector<unsigned short> inbuff;

	if(!inargs->size())
	{
 		ERROR_STREAM << "WcCommService::VisitModbusConnection() Command code missing" << endl;
		EXCEPTION_RETURN("WcCommService::VisitModbusConnection()"," Command code missing", "Modbus::error_write");
	}

	DEBUG_STREAM << "WcCommService::VisitModbusConnection() Handshake protocol: starts with PASSWD=0 " << endl;

	mba->PresetSingleRegister(WC_PASSWD, 0);


	DEBUG_STREAM << "WcCommService::VisitModbusConnection() Handshake protocol: wait for OUTCMD==0" << endl;

 	unsigned int    dodo_msec = 10;
 	struct timespec dodo;
 	dodo.tv_sec  = (dodo_msec / 1000);
 	dodo.tv_nsec = (dodo_msec % 1000) * 1000000;

 	unsigned int i;
 	for(i=0;i<(WC_TO/dodo_msec);i++)
 	{
  		nanosleep(&dodo, NULL);
  		DEBUG_STREAM  << "WcCommService::VisitModbusConnection() wago_cmd:read  " << dec << 3
  				<< " words at address: 0x" << hex << WC_NRES_MAX+4 << endl;


  		outbuff.clear();
  		mba->ReadInputRegisters(WC_VER,  3, outbuff);

 		DEBUG_STREAM << "address (VER)   : " << WC_VER    << " value: 0x"  << hex
 				<< (unsigned short)(outbuff[0])
 				<< dec << endl;
 		DEBUG_STREAM << "address (OUTCMD): " << WC_OUTCMD << " value: 0x"  << hex
  				<< (unsigned short)(outbuff[WC_OUTCMD-WC_VER])
  				<< dec << endl;

  		if(((outbuff[0]>>8)&0xff) != WC_VER_TAG)
  		{
  			ERROR_STREAM << "WcCommService::VisitModbusConnection() Invalid wago controller program version: 0x" << hex
	         	<< (unsigned short)(outbuff[0])  << dec << endl;
  			EXCEPTION_RETURN("WcCommService::VisitModbusConnection()","Invalid wago controller program version", "Modbus::error_write");
  		}

  		if(outbuff[WC_OUTCMD-WC_VER] == 0)
  		{
  			DEBUG_STREAM << "WcCommService::VisitModbusConnection() acknowledge from controller (OUTCMD==0)" << endl;
  			break;
	  	}
 	}
 	DEBUG_STREAM << "got it after " << dec << i << " loops" << endl;

 	if(i>=(WC_TO/dodo_msec))
 	{
 		ERROR_STREAM << "WcCommService::VisitModbusConnection() Timeout (pgm not ready) sending command 0x" << hex
        		<< (*inargs)[0]  << dec << endl;
  		EXCEPTION_RETURN("WcCommService::VisitModbusConnection()","Timeout (pgm not ready) sending command", "Modbus::error_write");
	}

 	DEBUG_STREAM << "WcCommService::VisitModbusConnection() Handshake protocol: write the command to process and its parameters" << endl;

 	inbuff.resize(2 + inargs->size());
	i=0;
	inbuff[i++] = WC_PASSWD_TAG;        // PASSWD
	inbuff[i++] = (*inargs)[0];   // INCMD
	inbuff[i++] = inargs->size()-1;      // NPAR
	for(unsigned int j = 1; j < inargs->size(); j++)
		inbuff[i++] = (*inargs)[j];  // PARi

	DEBUG_STREAM  << "WcCommService::VisitModbusConnection() write at address: 0x" << hex << WC_PASSWD << ": " << endl;
	DEBUG_STREAM  << "WcCommService::VisitModbusConnection() inargs:" << endl;

	mba->PresetMultipleRegisters(WC_PASSWD,inbuff);


	DEBUG_STREAM << "WcCommService::VisitModbusConnection() Handshake protocol: wait for end of command (OUTCMD==INCMD or ==0xffff)" << endl;


	dodo_msec    = DEF_WCCOMM_PERIOD;
	dodo.tv_sec  = (dodo_msec / 1000);
	dodo.tv_nsec = (dodo_msec % 1000) * 1000000;

	DEBUG_STREAM  << "WcCommService::VisitModbusConnection() read "<< dec <<  4 << " words at address: " << hex << WC_VER << dec << endl;
	for(i=0;i<(WC_TO/dodo_msec);i++)
	{
		nanosleep(&dodo, NULL);

		outbuff.clear();
		mba->ReadInputRegisters(WC_VER,   4, outbuff);
		if(outbuff[WC_OUTCMD-WC_VER] != 0)
		{
			if(outbuff[WC_OUTCMD-WC_VER] != (*inargs)[0] )
			{
				ERROR_STREAM  << "WcCommService::VisitModbusConnection() command failed in wago controller, error: 0x"
	           		<< hex << outbuff[WC_RES0-WC_VER] << dec << endl;

				EXCEPTION_RETURN("WcCommService::VisitModbusConnection()","command failed in wago controller", "Modbus::error_write");
			}
			else
			{
				DEBUG_STREAM << "WcCommService::VisitModbusConnection() acknowledge from controller (OUTCMD==INCMD)" << endl;
				break;
			}
		}
	}

	DEBUG_STREAM << "WcCommService::VisitModbusConnection() got it after " << dec << i << " loops" << endl;
 	if(i>=(WC_TO/dodo_msec))
 	{
 		ERROR_STREAM << "WcCommService::VisitModbusConnection() Timeout (pgm executed) sending command 0x" << hex
       		<< (*inargs)[0]  << dec << endl;
		EXCEPTION_RETURN("WcCommService::VisitModbusConnection()","Timeout (pgm executed)", "Modbus::error_write");
 	}

 	//
 	// Extract command argout parameters or error code
 	//
        // NOTE MP 2018Jan19: the TACO version reads all WC_NRES_MAX 
        // and therefore the nres information coming from WAGO embedded
        // program (ISGMAIN) is not used. Here it's used but not sure
        // if it's reliable 
        //
	unsigned int nres = outbuff[WC_NRES-WC_VER];
	outbuff.clear();
        if(nres > 0)
	    mba->ReadInputRegisters(WC_VER+4,   nres, outbuff);

	for(i=0;(i<outbuff.size()) && (i<WC_NRES_MAX);i++)
		(*outargs).push_back(outbuff[i]);

}
