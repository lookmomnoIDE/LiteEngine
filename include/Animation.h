#ifndef ANIMATION_H
#define ANIMATION_H 

#include <vector>

//#include "Vec2.h"
#include "sprite.h"

class Animation
{
	std::vector<Sprite> m_AnimCoords;
public:
	Animation(unsigned int animLength)
	{
		m_AnimCoords.reserve(animLength);
	}
	~Animation()
	{

	}

	void addSpriteToAnimation(unsigned int animLength, Sprite sprite)
	{
		m_AnimCoords.push_back(sprite);
	}

	std::vector<Vec2<float>>& getAnimation()
	{
		return m_AnimCoords;
	}


};


#endif