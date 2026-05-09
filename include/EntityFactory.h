#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H


class GameEngine;

class EntityFactory
{
	GameEngine* m_game = nullptr;
public:
	EntityFactory();
	void addSand(double xpos, double ypos);

};

#endif
