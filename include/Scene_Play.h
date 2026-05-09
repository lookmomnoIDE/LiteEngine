#ifndef SCENE_PLAY_H
#define SCENE_PLAY_H

#include "Scene.h"
#include "EntityManager.h"
#include "EntityFactory.h"
#include <iostream>

class Scene_Play : public Scene
{
	std::string m_level = "play";
	GameEngine* m_game = nullptr;
	Renderer* m_renderer = nullptr;

public:
	Scene_Play(GameEngine* game, Renderer* renderer);
	//void init(GameEngine* game) override;
	void update() override;
	void sAnimation();
	void sEnemySpawner(); 
	void sCollision();
	void sRender() override;
	void sDoAction();
	void sGUI();
	bool isPaused();

};


#endif