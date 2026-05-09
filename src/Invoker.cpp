#include "Invoker.h"


Invoker::~Invoker()
{
	delete m_start;
	delete m_stop;
}

void Invoker::setStart(ICommand *c)
{
	m_start = c;
}

void Invoker::setStop(ICommand *c)
{
	m_stop = c;
}

void Invoker::sendCommand()
{
	if (m_start)
	{
		m_start->execute();
	}

	/*else if (m_stop)
	{
		m_stop->execute();
	}*/
}