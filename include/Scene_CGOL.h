#ifndef SCENE_CGOL_H
#define SCENE_CGOL_H


#include "Scene.h"
#include "EntityManager.h"
#include "EntityFactory.h"
#include "Quad.h"
#include "Vec2.h"
#include "Grid.h"
#include "GeometryConstructor.h"

#include <iostream>

class Scene_CGoL : public Scene
{
	std::string m_level = "play";
	double m_x, m_y;
	bool m_primaryActionActive = false;
	std::vector<Quad<float>> m_quads;
	std::vector<std::vector<Quad<float>>> m_quadsList;
	unsigned int currentEntities = 0;
	unsigned int m_numQuads = 0;
	Grid grid;
	//size_t m_maxEntities;


public:
	Scene_CGoL(GameEngine* game, Renderer* renderer, size_t maxEntities);
	void init() override;
	void update() override;
	void sAnimation();
	void sEnemySpawner(); 
	void sCollision();
	void sRender() override;
	void sGUI();
	bool isPaused();
	void doAction(const Action& a) override;
	void registerAction(int keycode, const std::string& aName) override;
	void sDoAction() override;
	std::map<int, std::string>& getAM() override;

	EntityMemoryPool& getPool();
	EntityMan& getEntityMan();


};


#endif