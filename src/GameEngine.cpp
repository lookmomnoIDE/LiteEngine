#include "GameEngine.h"

GameEngine* GameEngine::Instance()
{
	static GameEngine instance{};
	std::cout << &instance << std::endl;
	return &instance;
}


GameEngine::~GameEngine()
{
	delete m_renderer;
	//m_renderer = nullptr;
	delete m_handler;
}


void GameEngine::Init()
{

	m_running = true;
	m_handler = new InputHandler();
	m_renderer = new Renderer();
	m_renderer->Init();
	//GLFWwindow* m_window = m_renderer->getWindow();
	m_scenes["play"] = std::make_unique<Scene_Play>(this, m_renderer);
	
	//m_factory = EntityFactory::Instance();
	m_factory->Init();
}


void GameEngine::update()
{

}


void GameEngine::run()
{

	changeScene<Scene_Play>("play", m_renderer);
	while(m_running)
	{
		m_entityMan->update();
		std::cout << "entity Man update" << std::endl;

		std::cout << "processInput" << std::endl;
		GameEngine::sUserInput();
		std::cout << "User Input" << std::endl;
		currentScene()->update();
		std::cout << "current scene update" << std::endl;
        currentScene()->sRender();
        std::cout << "current scene render" << std::endl;
		std::cout << m_currentFrame++ << std::endl;
	}
}


void GameEngine::quit()
{
	m_running = false;
	m_currentFrame = 0;
	std::cout << "Successful quit!" << std::endl;
}


/*void GameEngine::spawnEnemy()
{
	auto e = m_entityMan.addEntity("sand");
}*/

/*template <typename T, typename... Args>
void GameEngine::changeScene(const std::string name, Args&&... args)
{
    m_scenes[name] = std::make_unique<T>(this, std::forward<Args>(args)...);
    m_currentScene = name;
}*/

Scene* GameEngine::currentScene() {
    return m_scenes.count(m_currentScene) ? m_scenes[m_currentScene].get() : nullptr;
}


Renderer* GameEngine::getRenderer()
{
	return m_renderer;
}


EntityMemoryPool* GameEngine::getPool()
{
	return m_pool;
}


EntityMan* GameEngine::getEntityMan()
{
	return m_entityMan;
}


InputHandler* GameEngine::getHandler()
{
	return m_handler;
}


EntityFactory* GameEngine::getFactory()
{
	return m_factory;
}


void GameEngine::sUserInput()
{
	glfwPollEvents();
	std::cout << "Polled Events!" << std::endl;
	m_handler->processInput(m_renderer->getWindow());
	std::cout << "Processed Inputs!" << std::endl;
}

