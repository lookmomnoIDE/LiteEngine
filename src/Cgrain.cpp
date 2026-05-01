#include <Cgrain.h>

Cgrain::Cgrain()
{
	active = true;
}

Cgrain::Cgrain(float size)
	:m_size(size)
{
	active = true;
}

float Cgrain::getSize()
{
	return m_size;
}

void Cgrain::setSize(float size)
{
	m_size = size;
}
