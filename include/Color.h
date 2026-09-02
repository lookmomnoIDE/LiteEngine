#ifndef COLOR_H
#define COLOR_H

#include <string>


class Color 
{

public:
	float m_r, m_g, m_b, m_a;

	Color()
	{
		
	}
	Color(float r, float g, float b, float a)
	:m_r(r), m_g(g), m_b(b), m_a(a)
	{

	}
	Color(unsigned int r, unsigned int g, unsigned int b, unsigned int a = 255)
	{
		m_r = (float)r/255.0;
		m_g = (float)g/255.0;
		m_b = (float)b/255.0;
		m_a = (float)a/255.0;
	}
	~Color()
	{

	}
};




#endif