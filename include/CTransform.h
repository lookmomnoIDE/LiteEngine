#pragma once
#include <vector>
#include "Components.h"

class CTransform : public Component
{
	std::vector<float> 	m_pos 		= {0.0f, 0.0f};
	std::vector<float> 	m_vel 		= {0.0f, 0.0f};
public:
	
	CTransform();
	CTransform(const std::vector<float> & p, std::vector<float> & v);

	std::vector<float>& getPos();
	void setPos(std::vector<float> & p);

	std::vector<float>& getVel();
	void setVel(std::vector<float> & v);

};