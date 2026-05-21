#pragma once
#include "Components.h"
#include "Vec4.h"
#include <vector>

class Csand : public Component
{
	Vec4<float> 	m_color = {0.761f, 0.698f, 0.502f, 1.0f};


public:
	bool colorDirty = true;
	Csand();
	Csand(const Vec4<float>& color);

	Vec4<float>& getColor();
	void setColor(Vec4<float> color);
};
