#ifndef ICOMMAND_H
#define ICOMMAND_H


class ICommand
{
public:
	virtual ~ICommand(){}
	virtual void execute() const = 0;
	virtual void unexecute() const = 0;
};


#endif