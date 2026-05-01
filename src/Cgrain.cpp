#include <Cgrain.h>

Cgrain::Cgrain()
	:m_exists(true)
{}

Cgrain::Cgrain(float size)
	:m_size(size), m_exists(true)
{}

float Cgrain::getSize()
{
	return m_size;
}

void Cgrain::setSize(float size)
{
	m_size = size;
}
