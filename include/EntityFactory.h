#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "Vec2.h"
#include "Quad.h"
//#include "Scene.h"


class Scene;

class EntityFactory
{
	//GameEngine* m_game = nullptr;
public:
	EntityFactory();
	~EntityFactory();
	//static EntityFactory* Instance();
	void Init();
	void addSand(double xpos, double ypos);
	void addCell(Quad<float>& quad, Scene& scene);

};

#endif
