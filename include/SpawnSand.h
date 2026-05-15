#ifndef SPAWNSAND_H
#define SPAWNSAND_H 

#include "ICommand.h"
#include "PlayRec.h"
#include <iostream>


class LMB_ : public ICommand
{
	GameEngine* m_game = nullptr;
	

public:
	SpawnSand();
	void execute() override;
	void unexecute() override;
	bool isSpawning() override;

};


#endif