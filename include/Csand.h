#pragma once
#include "Components.h"
#include <vector>

class Csand : public Component
{
	bool 	m_exists = false;
	std::vector<float> 	m_color = {0.761f, 0.698f, 0.502f, 1.0f};

public:

	Csand();
	Csand(const std::vector<float> & color);

	std::vector<float> getColor();
	void setColor(std::vector<float> color);
};
