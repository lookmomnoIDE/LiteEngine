#ifndef CCELL_H
#define CCELL_H


class CCell : public Component
{

public:
	Quad<float> m_quad;
	CCell(){}
	CCell(Quad<float> quad)
	:m_quad(quad)
	{
		
		active = true;

	}

	Quad<float> getQuad()
	{
		return m_quad;
	}

	void setQuad(Quad<float> quad)
	{
		m_quad = quad;
	}

	void setColor(Vec4<float>& color)
	{
		m_quad.v0.setVColor(color);
		m_quad.v1.setVColor(color);
		m_quad.v2.setVColor(color);
		m_quad.v3.setVColor(color);
	}
};


#endif