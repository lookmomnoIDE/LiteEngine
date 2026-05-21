#include "CTransform.h"
//#include "Vec2.h"

CTransform::CTransform()
{
	active = true;
}
CTransform::CTransform(const Vec2<float>& p, Vec2<float>& v)
		:m_pos(p), m_vel(v)
{
	active = true;
}

Vec2<float>& CTransform::getPos()
{
	return m_pos;
}

void CTransform::setPos(Vec2<float>& p)
{
	m_pos = p;
}

Vec2<float>& CTransform::getVel()
{
	return m_vel;
}

void CTransform::setVel(Vec2<float>& v)
{
	m_vel = v;
}