#include "Cgravity.h"

Cgravity::Cgravity()
{
	active = true;
}

Cgravity::Cgravity(float gravity)
	:m_gravity(gravity)
{
	active = true;
}

Cgravity::~Cgravity()
{
	active = false;
}

float Cgravity::getGravity()
{
	return m_gravity;
}

void Cgravity::setGravity(float gravity)
{
	m_gravity = gravity;
}
/*
bool Cgravity::exists()
{
	return active;
}*/