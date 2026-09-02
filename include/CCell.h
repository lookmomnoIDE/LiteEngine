#ifndef CCELL_H
#define CCELL_H

//#include "tQuad.h"
#include "Quad.h"


class CCell : public Component
{

public:
	Quad<float> m_quad;
	//tQuad<float> m_tQuad;
	CCell(){}
	CCell(Quad<float> quad)
	:m_quad(quad)
	{
		
		active = true;

	}
/*	CCell(tQuad<float> quad)
	:m_tQuad(quad)
	{
		active = true;
	}*/

	Quad<float> getQuad()
	{
		return m_quad;
	}

	void setQuad(Quad<float> quad)
	{
		m_quad = quad;
	}

	void setColor(Color color)
	{
		m_quad.v0.setVColor(color);
		m_quad.v1.setVColor(color);
		m_quad.v2.setVColor(color);
		m_quad.v3.setVColor(color);
	}

/*	void setTexCoords(unsigned int FW, unsigned int FH, unsigned int frame)
	{
		m_tQuad.v0.setVTexCoord(Vec2<float>(frame * FW, 0));
		m_tQuad.v1.setVTexCoord(Vec2<float>(FW, 0));
		m_tQuad.v2.setVTexCoord(Vec2<float>(FW, FH));
		m_tQuad.v3.setVTexCoord(Vec2<float>(0, FH));
	}*/
};


#endif