#include "Csand.h"


Csand::Csand()
{
	active = true;
}


Csand::Csand(const Vec4<float> & color)
		:m_color(color)
{
	active = true;
}


Vec4<float>& Csand::getColor()
{
	return m_color;
}

void Csand::setColor(Vec4<float> color)
{
	m_color = color;
}