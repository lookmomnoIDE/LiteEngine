#ifndef GAMEENGINE_H
#define GAMEENGINE_H


#include "Scene.h"
#include "EntityManager.h"
#include "Renderer.h"
#include "InputHandler.h"
#include "Scene_Play.h"
#include "Scene_CGOl.h"
#include "Scene_test.h"
#include "EntityFactory.h"
#include "EntityMemoryPool.h"
#include "ICommand.h"
#include "assetManager.h"
#include <string>
#include <map>
#include <memory>
#include <iostream>


class Scene;


class GameEngine
{
	

	std::map<std::string, std::unique_ptr<Scene>> m_scenes;
	std::string m_scene;
	bool m_paused = false;
	bool m_running = false;
	unsigned int m_currentFrame = 0;
	std::string m_currentScene;
	Renderer* m_renderer = nullptr;		
	assetMan* m_assetMan = nullptr;
	unsigned int m_numRenderers = 0;
public:
	static GameEngine* Instance();
	~GameEngine();
	void Init();
	//void spawnEnemy();
	void update();
	void run();
	void quit();

	template <typename T, typename... Args>
	void changeScene(const std::string name, Args&&... args)
	{
		if (m_currentScene != name)
		{
			m_currentScene = name;
			m_scenes[name] = std::make_unique<T>(this, std::forward<Args>(args)...);
			currentScene()->init();
		}
		else if(m_currentScene == name)
		{
			currentScene()->init();
		}
		else
		{
			std::cout << "Error: What you talkin' bout Willis?!" << std::endl;
		}
		
	}
	Scene* currentScene();
	//Todo
	//Assets& getAssets();
	Renderer* getRenderer();
	EntityMemoryPool* getPool();
	EntityMan* getEntityMan();
	EntityFactory* getFactory();
	assetMan* getAssetMan();
	void sUserInput();
	unsigned int getUniqueRID();
	//aMap* getAM();
};

#endif