#ifndef SCENE_CGOL_H
#define SCENE_CGOL_H


#include "Scene.h"
#include "EntityManager.h"
#include "EntityFactory.h"
#include "Quad.h"
#include <iostream>

class Scene_CGoL : public Scene
{
	std::string m_level = "play";
	GameEngine* m_game = nullptr;
	Renderer* m_renderer = nullptr;
	double m_x, m_y;
	bool m_primaryActionActive = false;
	std::vector<Quad<float>> m_quads;
	unsigned int currentEntities = 0;

public:
	Scene_CGoL(GameEngine* game, Renderer* renderer);
	void init() override;
	void update() override;
	void sAnimation();
	void sEnemySpawner(); 
	void sCollision();
	void sRender() override;
	//void sDoAction();
	void sGUI();
	bool isPaused();
	void doAction(const Action& a) override;
	void registerAction(int keycode, const std::string& aName) override;
	void sDoAction() override;
	std::map<int, std::string>& getAM() override;


};


#endif