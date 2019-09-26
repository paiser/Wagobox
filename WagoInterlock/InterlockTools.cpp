/*
 * InterlockTools.cpp
 *
 *  Created on: Jul 12, 2013
 *      Author: kowalisz
 */

#include "InterlockTools.h"

#ifdef WAGO_SRV_INCLUDED
extern vector<string> string2vector(string &str, const char* tokens);
#else
vector<string> string2vector(string &str, const char* tokens)
{
	std::vector<std::string> fields;
	std::stringstream ss(str);
	std::string item;
	while(std::getline(ss, item, *tokens))
	{
		fields.push_back(item);
	}

	return fields;
}
#endif

/*!Process name of interlock or channel. Name can be specified with logical names with subarray syntax.
 * ex Temp - attribute related to attribute called Temp.
 * ex Temp[1] - attribute related to  2nd value in spectrum attribute called Temp.
 * ex Temp[1:3] - there are three attributes which are related to  2nd, 3rd and 4th value in spectrum attribute called Temp.
 *
 * \param rngname name string to be processed.
 * \param name	a place holder for a name of attribute found in string
 *
 * \return vector	which first element is indicating position of first value (0 if attribute is defined only by name),
 * 					if second element is present in vector it indicates that thre were multiple attributes defined in name(name[first:last]) this element
 * 					indicates position of last value. If vector is empty there was syntax error in given name.
 */
vector<unsigned short> ParseName(string rngname, string& name)
{
	unsigned short tmp;
	vector<unsigned short> ct;
	vector<string> nameV = string2vector(rngname, "[");
	if(nameV.size() > 1)
	{

		name = nameV[0];
		if(nameV[1].at(nameV[1].size()-1) != ']')
		{
			//Invalid channel range syntax return empty ct.
			return ct;
		}
		string channCountStr(nameV[1].substr(0,nameV[1].size() - 1 ));
		vector<string> countV = string2vector(channCountStr, ":");
		istringstream iss(countV[0]);
		iss >> tmp;
		ct.push_back(tmp);
		if(countV.size() > 1 )
		{
			istringstream iss2(countV[1]);
			iss2 >> tmp;
			ct.push_back(tmp);
		}else if(countV.size() > 2)
		{
			//Invalid channel range syntax return empty ct.
			ct.empty();
			return ct;
		}
	}else if(nameV.size() > 2){} //This is intentional if nameV.size() > 2 its error
	else
	{
		name = rngname;
		ct.push_back(0);
	}

	return ct;
}

/*! Converts string to format accepted by ISG protocol. Format is an array of short values,
 * each short value contains two character codes.
 * ex. 0x4942 = "IB"
 *
 *\param str	string for conversion.
 *\return	conversion result as vector of short values.
 */
vector<unsigned short> PackString(string str)
{
	vector<unsigned short> outVect;
	outVect.resize((str.size()/2) + 1, 0x0);

	unsigned int j = 0;
	for(unsigned int i=0; i < str.size(); i++)
	{
		if(!(i%2))
		{
			outVect[j] = ((unsigned short)str[i]) << 8;
		}
		else
		{
			outVect[j] = outVect[j] | ((unsigned short)str[i]);
			j++;
		}
	}

	return outVect;
}

/*!Decode string from format accepted by ISG protocol to string value (see PackString).
 *
 *\param pStr	isg coded string to be converted.
 *\return	converted string.
 */
string UnpackString(vector<short> pStr)
{
	std::string unpStr;
	for(unsigned j = 0; j < pStr.size(); j++) //unpack characters to string
	{
		if(pStr[j])
		{
			unpStr.push_back((char)((pStr[j]&0xff00)>>8));
			if(pStr[j]&0x00ff)
				unpStr.push_back((char)(pStr[j]&0x00ff));
			else
				break;
		}else
		{
			break;
		}
	}
	return unpStr;
}

/*!Converted given string of flag(interlock/channel flags) names to binary representation.
 *
 * \param txtFlags	string of interlock/channel flags for configuration.
 * \return binary value with raised corresponding flag bits.
 */
unsigned short FlagsTxt2Bin(string txtFlags)
{
	unsigned short flags = 0x0;

	string flg = txtFlags;
	std::transform(flg.begin(), flg.end(), flg.begin(), ::tolower);

	if(flg == "digital")
		flags = flags|IL_DIGITAL;
	else if(flg == "output")
		flags = flags|IL_OUTPUT;
	else if(flg == "unsigned")
		flags = flags|IL_UNSIGNED;
	else if(flg == "sticky")
		flags = flags|IL_STICKY;
	else if(flg == "inverted")
		flags = flags|IL_INVERTED;
	else if(flg == "disabled")
		flags = flags|IL_DISABLED;
	else if(flg == "noforce")
		flags = flags|IL_NOFORCE;

	return flags;
}

/*!Convert binary value to string holding names of flags raised in value.
 *
 * \param flags binary value holding flags.
 * \return string of names of raised flags.
 */
string FlagsBin2Txt(unsigned short flags)
{
	stringstream ss;

	ss << ((flags & IL_DIGITAL) ? "IL_DIGITAL " : "") ;
	ss << ((flags & IL_OUTPUT) ? "IL_OUTPUT " : "") ;
	ss << ((flags & IL_UNSIGNED) ? "IL_UNSIGNED " : "") ;
	ss << ((flags & IL_STICKY) ? "IL_STICKY " : "") ;
	ss << ((flags & IL_INVERTED) ? "IL_INVERTED " : "") ;
	ss << ((flags & IL_DISABLED) ? "IL_DISABLED " : "") ;
	ss << ((flags & IL_NOFORCE) ? "IL_NOFORCE " : "") ;
	ss << ((flags & IL_TRIP) ? "IL_TRIP " : "") ;
	ss << ((flags & IL_ALARM) ? "IL_ALARM " : "") ;
	ss << ((flags & IL_CNF_ERR) ? "IL_CNF_ERR " : "") ;
	ss << ((flags & IL_HDW_ERR) ? "IL_HDW_ERR " : "") ;

	return ss.str();
}

/*!Function for scalling value of threshold for writing into device. Converts physical value to binary.
 *
 * \param input  value for scalling.
 * \param type	 type of channel (determines scalling factor).
 *
 * \return 	converted binary value.
 */
unsigned short DoReverseScaling(float input, unsigned short type)
{

	if(type == ILCK_TYPE_TC )
	{
		return (unsigned short)(input*10);
	}
	if( type == ILCK_TYPE_IV || type == ILCK_TYPE_OV )
	{
		return (unsigned short)(input*0.1);
	}

	return  (unsigned short)input;
}

/*!Function for scalling value of threshold readed from device. Converts binary value to physical(float).
 *
 * \param input  value for scalling.
 * \param type	 type of channel (determines scalling factor).
 *
 * \return 	converted physicall value(float).
 */
float DoScaling(unsigned short input, unsigned short type)
{
	if(type == ILCK_TYPE_TC )
	{
		return ((float)input)*0.1;
	}
	if( type == ILCK_TYPE_IV || type == ILCK_TYPE_OV )
	{
		return ((float)input)*10.0;
	}
	return  (float)input;
}

/*!Generate exception with given description and add it to exception chain of provided exception object.
 *
 * \param ex	exception to which error chain new exception will be joined.
 * \param reason The exception DevError object reason field
 * \param desc The exception DevError object desc field
 * \param origin The exception DevError object origin field
 *
 * \return exception with modified chain.
 */
Tango::DevFailed AddToException(Tango::DevFailed ex,
				   string reason,
				   string desc,
				   string origin)
{
	long nb_err = ex.errors.length();
	ex.errors.length(nb_err + 1);

	ex.errors[nb_err].desc = CORBA::string_dup(desc.c_str());
	ex.errors[nb_err].severity = Tango::ERR;
	ex.errors[nb_err].reason = CORBA::string_dup(reason.c_str());
	ex.errors[nb_err].origin = CORBA::string_dup(origin.c_str());

	return ex;
}

/*!Generate exception object with given description without throwing.
 *
 * \param reason The exception DevError object reason field
 * \param desc The exception DevError object desc field
 * \param origin The exception DevError object origin field
 *
 * \return generated exception object.
 */
Tango::DevFailed CreateException(string reason,
				   string desc,
				   string origin)
{
	Tango::DevErrorList errors(1);

	errors.length(1);
	errors[0].severity = Tango::ERR;
	errors[0].reason = CORBA::string_dup(reason.c_str());
	errors[0].origin = CORBA::string_dup(origin.c_str());
	errors[0].desc = CORBA::string_dup(desc.c_str());

	return Tango::DevFailed(errors);
}
