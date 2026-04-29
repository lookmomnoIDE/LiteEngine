#include "CTransform.h"


CTransform::CTransform()
{}
CTransform::CTransform(const std::vector<float> & p, std::vector<float> & v)
		:m_pos(p), m_vel(v), m_exists(true)
{}

std::vector<float> CTransform::getPos()
{
	return m_pos;
}

void CTransform::setPos(std::vector<float> & p)
{
	m_pos = p;
}

std::vector<float> CTransform::getVel()
{
	return m_vel;
}

void CTransform::setVel(std::vector<float> & v)
{
	m_vel = v;
}