#include "SpawnSand.h"

SpawnSand::SpawnSand(float x, float y, PlayRec *rec)
:m_x(x), m_y(y), m_rec(rec)
{

}

void SpawnSand::execute() const 
{
	std::cout << "SpawnSand execute fn" << std::endl;
	m_rec->placeSand(m_x, m_y);
}


void SpawnSand::unexecute() const
{
	std::cout << "Stopping!" << std::endl;
}