#ifndef INVOKER_H
#define INVOKER_H

#include "ICommand.h"


class Invoker
{

	ICommand* m_start = 0;
	ICommand* m_stop = 0;
public:
	~Invoker();
	void setStart(ICommand *c);

	void setStop(ICommand *c);

	void sendCommand();

};
#endif