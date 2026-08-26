#ifndef SCENE_TEST_H
#define SCENE_TEST_H


#include "Scene.h"
#include "EntityManager.h"
#include "EntityFactory.h"
#include "Quad.h"
#include "tQuad.h"
#include "Vec2.h"
#include "Grid.h"
#include "GeometryConstructor.h"

#include <iostream>

class Scene_test : public Scene
{
	std::string m_level = "play";
	double m_x, m_y;
	bool m_primaryActionActive = false;
	std::vector<Quad<float>> m_quads;
	std::vector<tQuad<float>> m_tQuads;
	std::vector<std::vector<Quad<float>>> m_quadsList;
	unsigned int currentEntities = 0;
	unsigned int m_numQuads = 0;
	Grid grid;

	//size_t m_maxEntities;


public:
	Scene_test(GameEngine* game, Renderer* renderer, size_t maxEntities);
	~Scene_test(){}
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