#pragma once
#include "Components.h"


class Cgrain : public Component
{
	bool 				m_exists 	= false;
	float 				m_size 		= 0;
	
public:

	Cgrain();
	Cgrain(float size);
	float getSize();
	void setSize(float size);

};