#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H
#include "Animation.h"
#include <map>
#include <string>


class AnimationMan
{
	std::map<std::string, Animation*> 	m_Animations;
public:
	AnimationMan()
	{

	}


	~AnimationMan()
	{
		for (auto& [name, anim] : m_Animations)
		{
			delete anim;
		}
	}


	void addAnimation(std::string name, unsigned int animLength, float FW, float FH)
	{
		Animation* a = new Animation(animLength);
		for(unsigned int i = 0; i < animLength; i++)
		{
			Sprite s((float)i, FW, FH);
			a->addSpriteToAnimation(s);
		}
		m_Animations[name] = a;
	}
	
};


#endif