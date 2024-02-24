/*
 * Attributes.h
 *
 *  Created on: Jun 27, 2013
 *      Author: kowalisz
 */

#ifndef ATTRIBUTES_H_
#define ATTRIBUTES_H_

#include <tango.h>

namespace WagoInterlock_ns
{

/*!Class representing scalar or spectrum attribute in wago server. This class is
 * an interface for accessing attributes of wago server.
 */
class WagoAttribute
{
public:
	WagoAttribute(std::string nam, int dX );
	~WagoAttribute();
	void readAttribute(Tango::DeviceProxy* wagoDeviceProxyObj);
	float at(unsigned short pos);
	float* at_ptr(unsigned short pos);

	Tango::AttrQuality getQuality(){return quality;};
	unsigned int size();
	std::string getName(){return name;};

private:
	std::string name; //! Name of the corresponding wago attribute.
	int dimX; //!Dimension of the attribute (0 for scalar attribute).

	float *buff; //!Data buffer
	Tango::AttrQuality quality; //!Data quallity.

};

/*!Class representing attributes provided by interlock server to client. These attributes are linked
 * with corresponding wago attributes.
 *
 */
class InterlockAttribute: public Tango::Attr
{
public:
	InterlockAttribute(const char *name,long data_type,Tango::AttrWriteType w_type);
	~InterlockAttribute();
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att);
};

}
#endif /* ATTRIBUTES_H_ */
