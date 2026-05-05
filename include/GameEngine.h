#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Scene.h"
#include "EntityManager.h"
#include "Renderer.h"

#include "Scene_Play.h"
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
	GLFWwindow* m_window;

public:
	GameEngine();
	void spawnEnemy();
	void update();
	void run();
	void quit();

	template <typename T, typename... Args>
	void changeScene(const std::string name, Args&&... args)
	{
	    m_scenes[name] = std::make_unique<T>(this, std::forward<Args>(args)...);
	    m_currentScene = name;
	}
	Scene* currentScene();
	//Todo
	//Assets& getAssets();
	Renderer& getRenderer();
	EntityMemoryPool& getPool();
	EntityMan& getEntityMan();
	void sUserInput();

};

#endif