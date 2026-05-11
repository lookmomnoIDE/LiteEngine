#include "Invoker.h"

Invoker::Invoker()
{

}

Invoker::~Invoker()
{
	delete m_start;
	delete m_stop;
}

void Invoker::setStart(ICommand *c)
{
	std::cout << "offset of m_start: " << offsetof(Invoker, m_start) << std::endl;
	std::cout << "sizeof Invoker: "    << sizeof(Invoker) << std::endl;
	std::cout << "Begin Start, this= " << this << std::endl;
	this->m_start = c;
	std::cout << "Start set" << std::endl;
}

void Invoker::setStop(ICommand *c)
{
	m_stop = c;
}

void Invoker::sendCommand()
{	
	std::cout << "Pre-send command" << std::endl;
	if (m_start)
	{
		std::cout << "In start loop" << std::endl;
		m_start->execute();
		std::cout << "start sent" << std::endl;
	}

	else if (m_stop)
	{
		m_stop->unexecute();
	}
}