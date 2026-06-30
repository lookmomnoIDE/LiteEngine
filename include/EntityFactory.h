#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "Vec2.h"


class GameEngine;

class EntityFactory
{
	GameEngine* m_game = nullptr;
public:
	static EntityFactory* Instance();
	void Init();
	void addSand(double xpos, double ypos);
	void addCell(Vec2<float> pos);

};

#endif
