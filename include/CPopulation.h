#ifndef CPOPULATION_H
#define CPOPULATION_H

#include "Components.h"




class CPopulation : Component
{

public:
	unsigned int m_Pop = 500;


	Population(unsigned int pop)
	:m_Pop(pop)
	{

	}
	~Population()
	{

	}




};


#endif