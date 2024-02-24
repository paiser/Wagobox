/*
 * InterlockTools.h
 *
 *  Created on: Jul 12, 2013
 *      Author: kowalisz
 */

#ifndef INTERLOCKTOOLS_H_
#define INTERLOCKTOOLS_H_

#include <tango.h>

#define CMD_NAME			0x0001
#define	CMD_ACTIVE			0x0002

#define FUNC_INTERLOCK		0x0100

#define ILCK_CREATE			0x0101
#define ILCK_DELETE			0x0102
#define ILCK_ADDCHAN		0x0103
#define ILCK_DELCHAN		0x0104
#define ILCK_GETCONF		0x0105
#define ILCK_SETNAME		0x0106
#define ILCK_GETNAME		0x0107
#define ILCK_GETSTAT		0x0108
#define ILCK_SETFLGS		0x0109
#define ILCK_CLRGLGS		0x010A
#define ILCK_SETTHR			0x010B
#define ILCK_RESET			0x010C

#define IL_DIGITAL			0x0001
#define IL_OUTPUT			0x0002
#define IL_UNSIGNED			0x0004
#define IL_STICKY			0x0008
#define IL_INVERTED			0x0010
#define IL_DISABLED			0x0020
#define IL_NOFORCE			0x0080
#define IL_TRIP				0x0100
#define IL_ALARM			0x0200
#define IL_CNF_ERR			0x0400
#define IL_HDW_ERR			0x0800

#define IL_MODE_MASK		0x009F
#define IL_CH_FLAGS_MASK	0x003F


#define ILCK_TYPE_TC		(('T'<<8)+'C')
#define ILCK_TYPE_IV		(('I'<<8)+'V')
#define ILCK_TYPE_OV		(('O'<<8)+'V')
#define ILCK_TYPE_IW		(('I'<<8)+'W')
#define ILCK_TYPE_OW		(('O'<<8)+'W')
#define ILCK_TYPE_IB		(('I'<<8)+'B')
#define ILCK_TYPE_OB		(('O'<<8)+'B')

std::vector<std::string> string2vector(std::string &str, const char* tokens);
std::vector<unsigned short> ParseName(std::string rngname, std::string& name);
std::vector<unsigned short> PackString(std::string str);
std::string UnpackString(std::vector<short> pStr);
unsigned short FlagsTxt2Bin(std::string txtFlags);
std::string FlagsBin2Txt(unsigned short flags);
unsigned short DoReverseScaling(float input, unsigned short type);
float DoScaling(unsigned short input, unsigned short type);
Tango::DevFailed AddToException(Tango::DevFailed ex,
				   std::string reason,
				   std::string desc,
				   std::string origin);
Tango::DevFailed CreateException(std::string reason,
				   std::string desc,
				   std::string origin);

#endif /* INTERLOCKTOOLS_H_ */
