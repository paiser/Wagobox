// WagoModbusTango.cpp : Defines the entry point for the console application.
//

#include "targetver.h"

#include <iostream>
#include <stdio.h>
#include <string.h>
#ifdef WIN
#include <tchar.h>
#endif

#include "WagoDevice.h"

#define EERROR_CLOSE(_x_){ cout << _x_ << endl << "Test failed!" << endl; return -1;}


#include "ModbusAbstract.h"
class DummyModbus: public ModbusAbstract
{
public:
	DummyModbus():ModbusAbstract(NULL){};
	virtual int ReadDigitalInputs(unsigned int addr, unsigned int numOfInputs, vector<unsigned short>& dataBuffer){return 0;};
	virtual int ReadInputRegisters(unsigned int addr, unsigned int numOfRegisters, vector<unsigned short>& dataBuffer){return 0;};
	virtual int ReadHoldingRegisters(unsigned int addr, unsigned int numOfRegisters, vector<unsigned short>& dataBuffer){return 0;};
	virtual int ReadMultipleCoilsStatus(unsigned int addr,unsigned int numOfCoils, vector<unsigned short>& dataBuffer){return 0;};
	virtual int ForceMultipleCoils(unsigned int addr,unsigned int numOfCoils, vector<unsigned short>& values){return 0;};
	virtual int PresetMultipleRegisters(unsigned int addr,unsigned int numOfCoils, vector<unsigned short>& values){return 0;};
	virtual bool ModbusStateCheck(Tango::DevState& st){};
};


class test
{
public:
	void PrepareDeviceForTest1();
	void PrepareDeviceForTest2();
	void PrepareDeviceForTest3();
	
	int DoTest1();
	int DoTest2();
	int DoTest3();

	void DoCleanup1();
	void DoCleanup2();
	void DoCleanup3();

private:
	WagoDevice *wd;
	vector<PhysValueTransformer*> physTransformers;
	DummyModbus dMB;
};

void test::PrepareDeviceForTest1()
{
	wd = new WagoDevice();
	wd->buffers.modbusInterface = &dMB;
	dMB.bufferHolder = &wd->buffers;
	PhysValueTransformer* tr;
	PhysValueTransformer* tr0;
	tr0 = new PhysValueTransformer();
	physTransformers.push_back(tr0);
	
	wd->buffers.inputRegisters  = new unsigned short[30];
	memset(wd->buffers.inputRegisters, 0, 30*sizeof(unsigned short));
	//for(short i = 0; i<30; i++)
	//	wd->buffers.inputRegisters [i] = i;
	wd->buffers.inputRegisters[0] = 0;
	wd->buffers.inputRegisters [1] = 1;
	wd->buffers.inputRegisters [2] = 2;
	wd->buffers.inputRegisters [3] = 3;
	wd->buffers.inputRegisters [7] = 4;
	wd->buffers.inputRegisters [11] = 5;
	wd->buffers.inputRegisters [15] = 6;
	wd->buffers.inputRegisters [19] = 7;
	wd->buffers.inputRegisters [23] = 8;
	wd->buffers.inputRegisters [29] = -1;
	wd->buffers.numOfInputRegisters = 30;

	//Module 0
	Module* mod = new Module();
	mod->inputBaseAddr = &wd->buffers.inputRegisters[0];
	mod->inputOffset = 0;
	mod->numberOfChannels = 1;
	mod->numberOfInputs = 1;
	mod->physTransformer = tr0;
	wd->modules.push_back(mod);
	LogicalDevice* ld = new LogicalDevice();
	logDeviceValueMapping valMap = {mod, 0};
	ld->logicalChannels.push_back(valMap);
	wd->logicalDevices.push_back(ld);

	//Module 1
	mod = new Module();
	mod->inputBaseAddr= &wd->buffers.inputRegisters[1];
	mod->inputOffset = 1;
	mod->numberOfChannels = 2;
	mod->numberOfInputs = 1;
	mod->physTransformer = tr0;
	wd->modules.push_back(mod);
	ld = new LogicalDevice();
	valMap.module = mod;
	valMap.channel = 0;
	ld->logicalChannels.push_back(valMap);
	valMap.module = mod;
	valMap.channel = 1;
	ld->logicalChannels.push_back(valMap);
	wd->logicalDevices.push_back(ld);

	//Module 2
	mod = new Module();
	mod->inputBaseAddr= &wd->buffers.inputRegisters[3];
	mod->inputOffset = 3;
	mod->numberOfChannels = 1;
	mod->numberOfInputs = 4;
	tr = new ConfigurableSizePhysTransformer();
	((ConfigurableSizePhysTransformer*)tr)->bits = 32;
	((ConfigurableSizePhysTransformer*)tr)->scallingFactor = 1.0;
	((ConfigurableSizePhysTransformer*)tr)->sign = true;
	mod->physTransformer = tr;
	physTransformers.push_back(tr);
	wd->modules.push_back(mod);
	ld = new LogicalDevice();
	valMap.module = mod;
	valMap.channel = 0;
	ld->logicalChannels.push_back(valMap);
	wd->logicalDevices.push_back(ld);

	//Module 3
	mod = new Module();
	mod->inputBaseAddr= &wd->buffers.inputRegisters[7];
	mod->inputOffset = 7;
	mod->numberOfChannels = 2;
	mod->numberOfInputs = 4;
	mod->physTransformer = tr;
	wd->modules.push_back(mod);
	ld = new LogicalDevice();
	valMap.module = mod;
	valMap.channel = 0;
	ld->logicalChannels.push_back(valMap);
	valMap.channel = 1;
	ld->logicalChannels.push_back(valMap);
	wd->logicalDevices.push_back(ld);

	//Module 4
	/// one logical device with inputs from two modules
	mod = new Module();
	mod->inputBaseAddr= &wd->buffers.inputRegisters[15];
	mod->inputOffset = 15;
	mod->numberOfChannels = 2;
	mod->numberOfInputs = 4;
	mod->physTransformer = tr;
	wd->modules.push_back(mod);
	ld = new LogicalDevice();
//	valMap = {mod, 0};
//	ld->valuePoints.push_back(valMap);
	valMap.module = mod;
	valMap.channel = 1;
	ld->logicalChannels.push_back(valMap);
	mod = new Module();
	mod->inputBaseAddr= &wd->buffers.inputRegisters[23];
	mod->inputOffset = 23;
	mod->numberOfChannels = 2;
	mod->numberOfInputs = 2;
	mod->physTransformer = tr;
	wd->modules.push_back(mod);
	valMap.module = mod;
	valMap.channel = 0;
	ld->logicalChannels.push_back(valMap);
	wd->logicalDevices.push_back(ld);

	//Module 5
	mod = new Module();
	mod->inputBaseAddr= &wd->buffers.inputRegisters[29];
	mod->inputOffset = 29;
	mod->numberOfChannels = 1;
	mod->numberOfInputs = 1;
	mod->physTransformer = tr0;
	wd->modules.push_back(mod);
	ld = new LogicalDevice();
	valMap.module = mod;
	valMap.channel = 0;
	ld->logicalChannels.push_back(valMap);
	wd->logicalDevices.push_back(ld);

}


void test::PrepareDeviceForTest2()
{
	PrepareDeviceForTest1();
	wd->buffers.holdingRegistersWriteFlags = new bool[30];
	wd->buffers.holdingRegistersWriteBuff = wd->buffers.inputRegisters;
	wd->buffers.holdingRegisters = wd->buffers.inputRegisters;
	wd->buffers.numOfHoldingRegisters = wd->buffers.numOfInputRegisters;

	for(unsigned int i = 0; i < wd->modules.size(); i++)
	{
//		wd->modules[i]->outputBaseAddr = wd->modules[i]->inputBaseAddr; //For test 3 cmopatibility
		wd->modules[i]->numberOfOutputs = wd->modules[i]->numberOfInputs;
		wd->modules[i]->outputBaseWriteAddr = wd->modules[i]->inputBaseAddr;
		wd->modules[i]->outputOffset = wd->modules[i]->inputOffset;
		wd->modules[i]->outputWriteFlags = wd->buffers.holdingRegistersWriteFlags + wd->modules[i]->outputOffset;
	}
	
}

void test::PrepareDeviceForTest3()
{
	PrepareDeviceForTest2();
}

void test::DoCleanup2()
{
	DoCleanup1();
}


void test::DoCleanup3()
{
	DoCleanup1();
}


void test::DoCleanup1()
{
/*	delete[] (wd->buffers.inputRegisters);

	unsigned int i;
	for(i = 0; i < wd->logicalDevices.size(); i++)
		delete wd->logicalDevices[i];
	wd->logicalDevices.clear();

	for(i = 0; i < wd->modules.size(); i++)
		delete wd->modules[i];
	wd->modules.clear();

	delete wd;*/ //Not needed anymore
	unsigned int i;
	for(i = 0; i< this->physTransformers.size(); i++)
		delete physTransformers[i];
	physTransformers.clear();
}

int test::DoTest1()
{
	int j;
	cout << endl << " *** Test 1 - reads on dummy buffer *** " << endl;
	vector<float> values;
	for(j = 0; j < 6; j++)
	{
		cout << "Read phys for logicaldevice " << j;                                                                                                  
		wd->ReadPhys( j, values);
		for(unsigned int i = 0; i< values.size(); i++)
		{
			cout <<" values[" << i << "] = " << values[i] << endl;
		}
		switch(j)
		{
			case 0:
				if(values.size() != 1) EERROR_CLOSE("Invalid output vector size"); 
				if(values[0] !=  0) EERROR_CLOSE("Invalid output value");
				break;
			case 1:
				if(values.size() != 2) EERROR_CLOSE("Invalid output vector size"); 
				if((values[0] !=  1) || (values[1] !=  2)) EERROR_CLOSE("Invalid output value");
				break;
			case 2:
				if(values.size() != 1) EERROR_CLOSE("Invalid output vector size"); 
				if(values[0] !=  3) EERROR_CLOSE("Invalid output value");
				break;
			case 3:
				if(values.size() != 2) EERROR_CLOSE("Invalid output vector size"); 
				if((values[0] !=  4) || (values[1] !=  5)) EERROR_CLOSE("Invalid output value");
				break;
			case 4:
				if(values.size() != 2) EERROR_CLOSE("Invalid output vector size");
				if((values[0] !=  7)|| (values[1] !=  8)) EERROR_CLOSE("Invalid output value");
				break;
			case 5:
				if(values.size() != 1) EERROR_CLOSE("Invalid output vector size"); 
				if(values[0] !=  -1) EERROR_CLOSE("Invalid output value");
				break;
		}
		values.clear();
	}
	
	cout << "Test Passed" << endl ;		  
	return 0;
}

int test::DoTest2()
{
	cout << endl;
	cout << " *** Test 2 *** " << endl;
	cout << " *** Write and read sequence on cross buffer *** " << endl;
	vector<float> values;
	for(int j = 0; j < 6; j++)
	{
		cout << "Write phys for logicaldevice " << j;                                                                                                  
		values.push_back(0);;
		values.push_back((float)j);
		if(j == 4)
		{
			values.push_back(1);
			values.push_back((float)j);
		}
		cout <<" value = " << values[0] << endl;
		wd->WritePhys( j, values);
		values.clear();
	}
	
	for(int j = 0; j < 6; j++)
	{
		cout << "Read phys for logicaldevice " << j ;                                                                                                  
		wd->ReadPhys( j, values);
		for(unsigned int i = 0; i< values.size(); i++)
		{
			cout <<" value = " << values[i] << endl;
		}
		if(values[0] != j) EERROR_CLOSE("Invalid output value");
		if((j == 4) && (values[0] != j))  EERROR_CLOSE("Invalid output value");
		values.clear();
	}
	cout << "Test Passed" << endl ;				  
	return 0;
}

int test::DoTest3()
{
	unsigned int itr;
	float physVals[7] ;//= {1.0,  32767, 65535, 2147483647, -1.0, -32768,/* -2147483648*/};
	physVals[0] = 1.0f;
	physVals[1] = 32767;
	physVals[2] = 65535;
	physVals[3] = -1.0f;
	physVals[4] = -32768;
	physVals[5] = -65535;
	float valCheckTab[10];
	vector<float> values;
	unsigned int i;

	cout << endl;
	cout << " *** Test 3 *** " << endl;
	cout << " *** Write and read multiple values on cross buffer *** " << endl;

	values.push_back(0);
	values.push_back(0.0);
	cout << "Write phys for logicaldevice " << 0 << endl;
	cout <<"channel "<< values[0] <<" value = " << values[1] << endl;
	wd->WritePhys( 0, values);
	values.clear();
	valCheckTab[0] = (0.0);

	values.push_back(0);
	values.push_back(1.0);
	values.push_back(1);
	values.push_back(2.0);
	cout << "Write phys for logicaldevice " << 1 << endl;
	for(itr = 0; itr < values.size(); itr=itr+2)
		cout <<"channel "<< values[itr] <<" value = " << values[itr+1] << endl;
	wd->WritePhys( 1, values);
	values.clear();
	valCheckTab[1] = 1.0;
	valCheckTab[2] = 2.0;

	values.push_back(0);
	values.push_back(3.0);
	cout << "Write phys for logicaldevice " << 2 << endl;
	for(itr = 0; itr < values.size(); itr=itr+2)
		cout <<"channel "<< values[itr] <<" value = " << values[itr+1] << endl;
	wd->WritePhys( 2, values);
	values.clear();
	valCheckTab[3] = 3.0;

	values.push_back(0);
	values.push_back(4.0);
	values.push_back(1);
	values.push_back(5.0);
	cout << "Write phys for logicaldevice " << 3 << endl;
	for(itr = 0; itr < values.size(); itr=itr+2)
		cout <<"channel "<< values[itr] <<" value = " << values[itr+1] << endl;
	wd->WritePhys( 3, values);
	values.clear();
	valCheckTab[4] = 4.0;
	valCheckTab[5] = 5.0;


	values.push_back(0);
	values.push_back(6.0);
	values.push_back(1);
	values.push_back(7.0);
	cout << "Write phys for logicaldevice " << 4 << endl;
	for(itr = 0; itr < values.size(); itr=itr+2)
		cout <<"channel "<< values[itr] <<" value = " << values[itr+1] << endl;
	wd->WritePhys( 4, values);
	values.clear();
	valCheckTab[6] = 6.0;
	valCheckTab[7] = 7.0;


	values.push_back(0);
	values.push_back(8.0);
	cout << "Write phys for logicaldevice " << 5 << endl;
	for(itr = 0; itr < values.size(); itr=itr+2)
		cout <<"channel "<< values[itr] <<" value = " << values[itr+1] << endl;
	wd->WritePhys( 5, values);
	values.clear();
	valCheckTab[8] = 8.0;

	for( int i = 0; i < 6; i++)
		cout << "physVals[i]: " << physVals[i] << endl;

	for( int i = 0; i < 6; i++)
	{
		cout << "Write phys for LDs 2 & 3 value: " << physVals[i] << endl;
		values.push_back(0);
		values.push_back(physVals[i]);
		wd->WritePhys( 2, values);
		valCheckTab[3] = physVals[i];
		values.clear();

		values.push_back(0);
		values.push_back(physVals[i]);
		values.push_back(1);
		values.push_back(physVals[i]);
		wd->WritePhys( 3, values);
		valCheckTab[4] = physVals[i];
		valCheckTab[5] = physVals[i];
		values.clear();

		unsigned int valctr = 0;
		for( unsigned int j = 0; j< 6; j++)
		{
			cout << "Read phys LD " << j << endl;
			wd->ReadPhys(j,values);
			for(itr = 0; itr < values.size(); itr++)
			{
				cout << "Channel " << itr << " value: " << values[itr] <<  " expected: " << valCheckTab[valctr] << endl;
				if(valCheckTab[valctr] != values[itr] )
				{
					cout << "Test Failed!" << endl ;
					return -1;
				}
				valctr++;
			}
			values.clear();

		}
	}

	cout << "Test Passed" << endl ;
	return 0;
}

#ifdef WIN
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	test t;
	try{
	t.PrepareDeviceForTest1();
	t.DoTest1();
	t.DoCleanup1();

	t.PrepareDeviceForTest2();
	t.DoTest2();
	t.DoCleanup2();

	t.PrepareDeviceForTest3();
	t.DoTest3();
	t.DoCleanup3();
	return 0;
	}catch(std::string err)
	{
		cout << err << endl;
	}

}

