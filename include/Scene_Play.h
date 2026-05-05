#ifndef SCENE_PLAY_H
#define SCENE_PLAY_H

#include "Scene.h"
#include "EntityManager.h"
#include <iostream>

class Scene_Play : public Scene
{
	std::string m_level;

public:
	void init();
	void update();
	void sAnimation();
	void sEnemySpawner();
	void sCollision();
	void sRender();
	void sDoAction();
	void sGUI();

};


#endif