#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <map>


class Command
{
	std::string m_name = "NONE";
	std::string m_type = "NONE";
public:
	virtual ~Command();
	virtual Command(const std::string name, const std::string type):m_name(name), m_type(type) {}
	const std::string name() const {return m_name;}
	const std::string type() const {return m_type;}
	virtual void execute() = 0;

};


class PlaceCommand : public Command
{
public:
	virtual void execute() override	{addSand();}
};


class InputHandler
{
	Command* LMB_;
	Command* ESC_;
public:
	void handleInput(std::string name, std::string type)
	{
		if (name == "_LMB")
		{
			&LMB_->execute();
		}
	}
}


#endif
