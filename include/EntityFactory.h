#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H
#include "GameEngine.h"

class EntityFactory
{
	GameEngine* m_game;
public:
	EntityFactory(GameEngine* game);
	void addSand(double xpos, double ypos);

};

#endif
