#include "EntityManager.h"
#include "Renderer.h"
#include "Scene.h"
#include <string>
#include <map>


EntityMan EntityManager;




class GameEngine
{
	std::map<std::string, Scene> m_scenes;
	std::string m_scene;
	Assets m_assets;	//TODO
	bool paused = false;
	bool running = true;
	unsigned int m_currentFrame = 0;

public:
	GameEngine();
	void MainLoop();
	void spawnEnemy();
	void update();
	void run();
	void quit();
	void chaneScene();
	Assets& getAssets();
	//window??????
	Renderer::GLFWwindow* window();
	void sUserInput();

};