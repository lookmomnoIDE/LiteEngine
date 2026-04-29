#include <Cgrain.h>

Cgrain::Cgrain()
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
