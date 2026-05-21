#pragma once
#include "Components.h"
#include "Quad.h"
#include "Vertex.h"
#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"
#include <vector>



class Cgrain : public Component
{
	float 	m_size 			= 0.01f;
	float 	m_aspectRatio	= 1050.0f/1920.0f;
	Quad	m_quad;
public:

	Cgrain();
	Cgrain(float size);
	float getSize();
	void setSize(float size);
	Quad createQuad(const Vec2<float>& pos, const Vec4<float>& color);
	Quad& getQuad();
	void setQuadPos(Vec2<float>& pos);
	void setQuadColor(Vec4<float>& color);


};