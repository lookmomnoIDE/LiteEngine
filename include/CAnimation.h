#ifndef CANIMATION_H
#define CANIMATION_H
#include <string>


class CAnimation : public Component
{

	std::string m_Name = "NULL";
	unsigned int m_Frame = 0;
public:

	CAnimation(){}
	CAnimation(std::string name, unsigned int frame)
	:m_Name(name), m_Frame(frame)
	{
		active = true;
	}

	std::string getName()
	{
		return m_Name;
	}

	unsigned int getFrame()
	{
		return m_Frame;
	}

	void setName(std::string name)
	{
		m_Name = name;
	}

	void setFrame(unsigned int frame)
	{
		m_Frame = frame;
	}

};


#endif