//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wago Modbus Tango Server
//  @ File Name : Module.h
//  @ Date : 2013-02-03
//  @ Author : Pawel Kowaliszyn
//
//


#if !defined(_MODULE_H)
#define _MODULE_H

#include "PhysValueTransformer.h"
#include "ModuleDB.h"

class BufferHolder;

/*!Class representing input/output module connected to wago device.
 *
 */
class Module
{
public:
	Module();
	virtual ~Module();
	virtual int ReadPhysIn(unsigned short channel, float& values);
	virtual int ReadPhysOut(unsigned short channel, float& values);
	virtual void WritePhys(unsigned short channel, float& values);
	virtual void WriteDigi(unsigned short channel, vector<unsigned short>& values);
	virtual void ReadDigiIn(unsigned short channel, vector<unsigned short>& values);
	void ReadDigiOut(unsigned short channel, vector<unsigned short>& values);

	bool IsWithinAddresRange(unsigned short* addr, unsigned int channel);
	unsigned int GetNumOfOutputs(){ return numberOfOutputs; };
	wagoModuleDesc* GetModuleDescriptor(){ return moduleDescriptor; };
	unsigned short GetInputOffset(unsigned short channel);
	unsigned short GetOutputOffset(unsigned short channel);

protected:
	unsigned short *inputBaseAddr; //!Pointer to input base in buffer
	unsigned short *outputBaseAddr; //!Pointer to output base in buffer
	unsigned short *outputBaseWriteAddr; //!Pointer to base in write buffer
	bool *outputWriteFlags; //!Pointer to  flags in flags buffer

	unsigned int numberOfChannels; //!Number of module channels
	unsigned int numberOfInputs; //!Number of module inputs in one channel
	unsigned int numberOfOutputs; //!Number of module outputs in one channel

	wagoModuleDesc *moduleDescriptor; //!Pointer to module description sturcture.

	unsigned short inputOffset; //!Offset of first input in process image
	unsigned short outputOffset; //!Offset of first output in process image

	friend class Configurator;

	LOGGING_ADDONS;
};

/*! Class representing Wago 637 Incremental Encoder Interface module.
 *
 */
class M637Module: public Module
{
public:
	M637Module();

	virtual int ReadPhysIn(unsigned short channel, float& values);
	virtual int ReadPhysOut(unsigned short channel, float& values);
	virtual void WritePhys(unsigned short channel, float& values);
	virtual void WriteDigi(unsigned short channel, vector<unsigned short>& values);
	virtual void ReadDigiIn(unsigned short channel, vector<unsigned short>& values);
	virtual void ReadDigiOut(unsigned short channel, vector<unsigned short>& values);
};

#endif  //_MODULE_H
