#include "GameEngine.h"

GameEngine::GameEngine()
	:m_running(true)
{
	m_renderer = new Renderer();
	//GLFWwindow* m_window = m_renderer->getWindow();
	m_scenes["play"] = std::make_unique<Scene_Play>(this, m_renderer);
}


GameEngine::~GameEngine()
{
	delete m_renderer;
	m_renderer = nullptr;
}


void GameEngine::update()
{

}


void GameEngine::run()
{
	changeScene<Scene_Play>("play", m_renderer);
	while(m_running)
	{
		m_entityMan.update();
		std::cout << "entity Man update" << std::endl;
		glfwPollEvents();
		processInput(m_renderer->getWindow()); 	//put in UI system
		std::cout << "processInput" << std::endl;
		GameEngine::sUserInput();
		std::cout << "User Input" << std::endl;
		currentScene()->update();
		std::cout << "current scene update" << std::endl;
        currentScene()->sRender();
        std::cout << "current scene render" << std::endl;
        
		glfwSwapBuffers(m_renderer->getWindow());
					//put in UI system
		std::cout << m_currentFrame++ << std::endl;
	}
}


void GameEngine::quit()
{
	m_running = false;
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


Renderer& GameEngine::getRenderer()
{
	return *m_renderer;
}


EntityMemoryPool& GameEngine::getPool()
{
	return m_pool;
}


EntityMan& GameEngine::getEntityMan()
{
	return m_entityMan;
}


void GameEngine::sUserInput()
{
	std::cout << "Hello Monkeys!!!" << std::endl;
}


void GameEngine::processInput(GLFWwindow* window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
		GameEngine::quit();
	}
	
}

