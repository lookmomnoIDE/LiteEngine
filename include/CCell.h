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
};


#endif