/*
 * Attributes.cpp
 *
 *  Created on: Jun 27, 2013
 *      Author: kowalisz
 */
#include "Attributes.h"

namespace WagoInterlock_ns
{

/*!The default constructor.
 *
 * \param nam	name of the corresponding wago server attribute.
 * \param dX	dimmension of corresponding wago server attribute (0 for scalar attribute).
 */
WagoAttribute::WagoAttribute(string nam, int dX ):
		dimX(dX),
		name(nam)
{
	buff = new float[dimX];
}

/*!The default destructor.
 *
 */
WagoAttribute::~WagoAttribute()
{
	if(buff)
		delete buff;
}

/*!Read attribute values from remote server and store it in objects attribute.
 *
 *\param wagoDeviceProxyObj		pointer to Wago Tango server interface object.
 */
void WagoAttribute::readAttribute(Tango::DeviceProxy* wagoDeviceProxyObj)
{
	Tango::DeviceAttribute dAttr;
	std::vector<float> output;
	dAttr  = wagoDeviceProxyObj->read_attribute(this->name);

	if(dimX == 1)
	{
		dAttr >> (*buff);
	}else
	{
		vector<float> tmpBuffer;
		dAttr >> tmpBuffer;

		int retBuffSize = tmpBuffer.size();
		for(int i = 0; i < ((dimX >= retBuffSize )? retBuffSize : dimX); i++ )
		{
			buff[i] = tmpBuffer[i];
		}
	}

	Tango::AttrQuality qBuff = dAttr.get_quality();
	if( qBuff > Tango::ATTR_INVALID )
		this->quality = Tango::ATTR_VALID;
	else
		this->quality = qBuff;
	//this->quality = dAttr.get_quality();
}

/*!Return value of attribute at given position.
 *
 * \param pos	position at the value vector(for scallar attributes always 0);
 * \return	found value
 */
float WagoAttribute::at(unsigned short pos)
{
	return buff[pos];
}

/*!Return pointer to float value of attribute at given position.
 *
 * \param pos	position at the value vector(for scallar attributes always 0);
 * \return	pointer to found value;
 */
float* WagoAttribute::at_ptr(unsigned short pos)
{
	return &(buff[pos]);
}

/*!Return number of elements collected by attribute.
 *
 * \return size of attribute.
 */
unsigned int WagoAttribute::size()
{
	return dimX;
}

/*!The default constructor
 *
 * \param name name of the attribute.
 * \param data_type	attribute data type.
 * \param w_type The attribute type (read, write, read with write ...).
 * \param wagoAtt pointer to corresponding wago attribute interface.
 * \param pos	position in corresponding wago attribute.
 */
InterlockAttribute::InterlockAttribute(const char *name, long data_type, Tango::AttrWriteType w_type):
Attr(name,data_type,w_type)
{

}

/*!The default constructor.
 *
 */
InterlockAttribute::~InterlockAttribute()
{

}

/*!Read attributeValue. This method gets attribute value from corresponding wago attribute interface object
 * and delivers it to Tango library.
 *
 * \param dev	pointer to calling Interlock device server object.
 * \param att	reference to Tango attribute object in which attribute data will be stored.
 */
void InterlockAttribute::read(Tango::DeviceImpl *dev,Tango::Attribute &att)
{
	dev->read_attr(att);
}

}
