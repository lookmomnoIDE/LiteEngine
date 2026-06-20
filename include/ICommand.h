#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <string>

class Action
{
	std::string m_name = "NONE";
	std::string m_type = "NONE";	
public:
	Action(std::string name, std::string type)
		:m_name(name), m_type(type){}
	virtual ~Action() = default;
	const std::string& name() const {return m_name;}
	const std::string& type() const {return m_type;}

};



#endif