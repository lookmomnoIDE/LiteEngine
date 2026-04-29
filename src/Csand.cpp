#include "Csand.h"


Csand::Csand()
		:m_exists(true)
{}


Csand::Csand(const std::vector<float> & color)
		:m_color(color), m_exists(true)
{}


std::vector<float> Csand::getColor()
{
	return m_color;
}

void Csand::setColor(std::vector<float> color)
{
	m_color = color;
}