#pragma once
#include <vector>
#include "Components.h"
#include "Vec2.h"


class CTransform : public Component
{
	Vec2<float> 	m_pos 		= {0.0f, 0.0f};
	Vec2<float> 	m_vel 		= {0.0f, 0.0f};
public:
	
	CTransform();
	CTransform(Vec2<float> p);
	CTransform(Vec2<float> & p, Vec2<float> & v);

	Vec2<float>& getPos();
	void setPos(Vec2<float> & p);

	Vec2<float>& getVel();
	void setVel(Vec2<float> & v);

};