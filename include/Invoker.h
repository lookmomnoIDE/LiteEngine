#ifndef INVOKER_H
#define INVOKER_H

#include "ICommand.h"
#include <iostream>
#include <cstddef>


class Invoker
{

	ICommand *m_start;
	ICommand *m_stop;
public:
	Invoker();
	~Invoker();
	void setStart(ICommand *c);

	void setStop(ICommand *c);

	void sendCommand();

};
#endif