#ifndef CHARACTER_H
#define CHARACTER_H

#include "Vec2.h"
class Character
{

public:
	unsigned int m_texID;
	Vec2<int> m_size;
	Vec2<int> m_bearing;
	unsigned int Advance;
	Character(unsigned int texID, Vec2<int> size, Vec2<int> bearing, unsigned int Advance)
	:m_texID(texID), m_size(size), m_bearing(bearing), Advance(Advance)
	{

	}
	~Character(){}
};


#endif