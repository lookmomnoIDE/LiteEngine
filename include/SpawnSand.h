#ifndef SPAWNSAND_H
#define SPAWNSAND_H 

#include "ICommand.h"
#include "PlayRec.h"


class SpawnSand : public ICommand
{

	float m_x, m_y;
	PlayRec* m_rec;
public:
	SpawnSand(float x, float y, PlayRec *rec);
	void execute() const override;

};


#endif