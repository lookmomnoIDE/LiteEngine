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
};


#endif

#include "EntityFactory.h"

class InputHandler
{
public:
	void doCommand(float x, float y)
	{
		EntityFactory::addSand(x, y);
	}
};

class ICommand
{
public:
	virtual ~ICommand(){}
	virtual void execute() const = 0;
};

class SpawnSand : public ICommand
{
	InputHandler* m_handler;
	float m_x, m_y;
public:

	SpawnSand(InputHandler* handler, float x, float y)
		:m_handler(handler), m_x(x), m_y(y)
	{
		
	}

	void execute() const override 
	{
		m_handler->doCommand(m_x, m_y);
		
	}
};


//simple example
SpawnSand s(m_xpos, m_ypos);
s.execute();



InputHandler handler;
//this
SpawnSand s(&handler, x, y)
s.execute();

//or this?
SpawnSand(&handler, x, y).execute()