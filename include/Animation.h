#ifndef ANIMATION_H
#define ANIMATION_H 

#include <vector>

#include "Vec2.h"
#include "sprite.h"

class Animation
{
	std::vector<Sprite> m_AnimCoords;
public:
	Animation()
	{

	}
	~Animation()
	{

	}

	void addAnimation(unsigned int animLength, unsigned int FW, unsigned int FH, unsigned int row, unsigned int col)
	{
		m_AnimCoords.reserve(animLength);
		for(unsigned int i = 0; i <= animLength; i++)
		{
			m_AnimCoords.push_back(Vec2<float>((col + i)*FW, row*FH));
		}
	}

	std::vector<Vec2<float>>& getAnimation()
	{
		return m_AnimCoords;
	}


};


#endif