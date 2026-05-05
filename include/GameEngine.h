#include "EntityManager.h"
#include "Renderer.h"
#include "Scene.h"
#include <string>
#include <map>
#include <memory>


class GameEngine
{
	std::map<std::string, std::unique_ptr<Scene>> m_scenes;
	std::string m_scene;
	//Assets m_assets;	//TODO
	bool m_paused = false;
	bool m_running = false;
	unsigned int m_currentFrame = 0;
	std::string m_currentScene;
	EntityMemoryPool& m_pool = EntityMemoryPool::Instance();
	EntityMan& m_entityMan = EntityMan::Instance();
	Renderer& m_renderer;

public:
	GameEngine();
	void spawnEnemy();
	void update();
	void run();
	void quit();

	void chaneScene(const std::string name, Args&&... args);
	Scene* currentScene();
	//Todo
	//Assets& getAssets();
	Renderer& getRenderer();
	EntityMemoryPool& getPool();
	EntityMan& getEntityMan();
	void sUserInput();

};