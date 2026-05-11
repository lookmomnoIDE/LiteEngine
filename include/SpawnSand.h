#ifndef SPAWNSAND_H
#define SPAWNSAND_H 

#include "ICommand.h"
#include "PlayRec.h"
#include <iostream>


class SpawnSand : public ICommand
{

	//float m_x, m_y;
	PlayRec* m_rec = nullptr;
	GameEngine* m_game = nullptr;
	double m_xpos, m_ypos;
public:
	SpawnSand(PlayRec *rec, GameEngine* game);
	void execute() override;
	void unexecute() const override;

};


#endif