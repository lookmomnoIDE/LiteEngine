#ifndef SPRITE_H
#define SPRITE_H

#include "Quad.h"

#include <array>

class Sprite
{
	std::array<Vec2<float>, 4> m_Sprite;
public:
	addSprite(float frame, float FW, float FH, )
	{
		m_Sprite[0] = Vec2<float>(frame * FW, 0);
		m_Sprite[1] = Vec2<float>((frame * FW)+ FW, 0);
		m_Sprite[2] = Vec2<float>(frame * FW, FH);
		m_Sprite[3] = Vec2<float>((frame * FW) + FW, FH);
	}
	getSprite()
	{
		return m_Sprite;
	}

};


#endif