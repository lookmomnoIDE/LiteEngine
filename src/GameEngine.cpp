#include "GameEngine.h"

GameEngine::GameEngine()
	:m_running(true)
{
	GLFWwindow* m_window = g.getRenderer().getWindow();
}


void GameEngine::update()
{

}


void GameEngine::run()
{
	while(m_running)
	{
		m_entityMan.update();
		processInput(m_window); 	//put in UI system
		currentScene()->update();
        currentScene()->sRender();
        GameEngine::sUserInput();
		glfwSwapBuffers(m_window);
		glfwPollEvents();			//put in UI system
		m_currentFrame++;
	}
}


void GameEngine::quit()
{
	m_running = false;
}


void GameEngine::spawnEnemy()
{
	auto e = m_entityMan.addEntity("enemy");
}

template <typename T, typename... Args>
void GameEngine::changeScene(const std::string name, Args&&... args)
{
    m_scenes[name] = std::make_unique<T>(this, std::forward<Args>(args)...);
    m_currentScene = name;
}

Scene* GameEngine::currentScene() {
    return m_scenes.count(m_currentScene) ? m_scenes[m_currentScene].get() : nullptr;
}


Renderer& GameEngine::getRenderer()
{
	return m_renderer;
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
		g.quit();
	}
	
}

