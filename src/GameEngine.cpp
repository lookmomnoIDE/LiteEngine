#include "GameEngine.h"

GameEngine::GameEngine()
	:m_running(true)
{
	
	//GLFWwindow* window = renderer.getWindow();
}


void GameEngine::update()
{

}


GameEngine::run()
{
	while(m_running)
	{
		m_entityMan.update();
		processInput(m_window);
		GameEngine::sUserInput();
		currentScene()->update();
        currentScene()->sRender();
		glfwSwapBuffers(m_window);
		glfwPollEvents();
		m_currentFrame++;
	}
}


void GameEngine::quit()
{

}

/*void GameEngine::MainLoop()
{
	//EntityManager.update()
	Scene_Play::sUserInput();
	Scene_Play::sMovement();
	Scene_Play::sCollision();
	Scene_Play::sRender();
	m_currentFrame++;
}*/

void GameEngine::spawnEnemy()
{
	auto e = EntityManager.addEntity("enemy");
}

template <typename T, typename... Args>
void GameEngine::changeScene(const std::string name, Args&&... args)
{
	m_scenes[name] = std::unique_ptr<T>(this, std::forward<Args>(args)...);
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
	
}
