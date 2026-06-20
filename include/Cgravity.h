#ifndef CGRAVITY_H
#define CGRAVITY_H
#include "Components.h"


class Cgravity : public Component
{
	float m_gravity = -0.00001;
public:
	Cgravity();
	Cgravity(float gravity);
	~Cgravity();
	float getGravity();
	void setGravity(float gravity);
};

#endif