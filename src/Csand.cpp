#include "Csand.h"


Csand::Csand()
{
	active = true;
}


Csand::Csand(const std::vector<float> & color)
		:m_color(color)
{
	active = true;
}


std::vector<float> Csand::getColor()
{
	return m_color;
}

void Csand::setColor(std::vector<float> color)
{
	m_color = color;
}