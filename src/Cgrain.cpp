#include "Cgrain.h"
#include <iostream>


Cgrain::Cgrain()
{
	active = true;
}


Cgrain::Cgrain(const Vec2<float>& pos, Vec4<float>& color, float size)
{
	active = true;
	m_size = size;
	createQuad(pos, color);
}


Cgrain::Cgrain(float size)
	:m_size(size)
{
	active = true;
}

float Cgrain::getSize()
{
	return m_size;
}

void Cgrain::setSize(float size)
{
	m_size = size;
}



Quad<float> Cgrain::createQuad(const Vec2<float>& pos, Vec4<float>& color)
{
	float halfX = (m_size * m_aspectRatio) / 2.0f;
	float halfY = m_size / 2.0f;

	m_quad.v0.Position 	= {pos.m_x - halfX, pos.m_y - halfY, 1.01f};
	m_quad.v0.Color 	= {color.m_x, color.m_y, color.m_z, color.m_w};

	m_quad.v1.Position = {pos.m_x + halfX, pos.m_y - halfY, 1.01f};
	m_quad.v1.Color 	= {color.m_x, color.m_y, color.m_z, color.m_w};

	m_quad.v2.Position = {pos.m_x - halfX, pos.m_y + halfY, 1.01f};
	m_quad.v2.Color 	= {color.m_x, color.m_y, color.m_z, color.m_w};

	m_quad.v3.Position = {pos.m_x + halfX, pos.m_y + halfY, 1.01f};
	m_quad.v3.Color 	= {color.m_x, color.m_y, color.m_z, color.m_w};

	return m_quad;
}


Quad<float>& Cgrain::getQuad()
{
	return m_quad;
}

void Cgrain::setQuadPos(Vec2<float>& pos)
{
	float halfX = (m_size * m_aspectRatio) / 2.0f;
	float halfY = m_size / 2.0f;
	m_quad.v0.Position = {pos.m_x - halfX, pos.m_y - halfY, -1.0f};
	m_quad.v1.Position = {pos.m_x + halfX, pos.m_y - halfY, -1.0f};
	m_quad.v2.Position = {pos.m_x - halfX, pos.m_y + halfY, -1.0f};
	m_quad.v3.Position = {pos.m_x + halfX, pos.m_y + halfY, -1.0f};
}


void Cgrain::setQuadColor(Vec4<float>& color)
{
	m_quad.v0.Color = {color};
	m_quad.v1.Color = {color};
	m_quad.v2.Color = {color};
	m_quad.v3.Color = {color};
}