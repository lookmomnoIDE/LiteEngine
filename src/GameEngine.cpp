#include "GameEngine.h"

float green[4] = {0.0f, 1.0f, 0.0f, 1.0f};



GameEngine* GameEngine::Instance()
{
	static GameEngine instance{};
	//std::cout << &instance << std::endl;
	return &instance;
}


GameEngine::~GameEngine()
{
	delete m_renderer;
	delete m_assetMan;
	//m_renderer = nullptr;


}


void GameEngine::Init()
{

	m_running = true;

	m_assetMan = new assetMan();
	m_renderer = new Renderer();
	m_renderer->Init();
	//m_scenes["play"] = std::make_unique<Scene_Play>(this, m_renderer, 10000);
	//m_scenes["CGoL"] = std::make_unique<Scene_CGoL>(this, m_renderer, 30000);
	//m_scenes["test"] = std::make_unique<Scene_test>(this, m_renderer, 1000);
	//m_factory->Init();
	InputHandler::Instance();
	InputHandler::Instance().Init();
	m_assetMan->addFont("IBM", "fonts/short/Mx437_IBM_3270pc.ttf");
	
	
}


void GameEngine::update()
{

}


void GameEngine::run()
{
	std::string sFPS;
	//changeScene<Scene_CGoL>("CGoL", m_renderer, (192*105));
	changeScene<Scene_test>("test", m_renderer, 50);
	//currentScene()->init();

	//changeScene<Scene_Play>("play", m_renderer);
	while(m_running)
	{
		//auto currentSeconds = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch());
		//auto now = std::chrono::steady_clock::now();
		//m_entityMan->update();
		GameEngine::sUserInput();
		
		currentScene()->update();
		
		currentScene()->sRender();
		
		currentScene()->sDoAction();

		
		if(m_engineOverlay)
		{
			if(m_frameCount >= 60)
			{
				sFPS = calcumalateFPS();
			}
			m_renderer->drawText(sFPS, 1790.0f, 1000.0f, "IBM", 0.5f, green);
		}
		m_frameCount++;
		m_renderer->SwapBuffers();
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


Renderer* GameEngine::getRenderer()
{
	return m_renderer;
}


/*EntityMemoryPool* GameEngine::getPool()
{
	return m_pool;
}


EntityMan* GameEngine::getEntityMan()
{
	return m_entityMan;
}


EntityFactory* GameEngine::getFactory()
{
	return m_factory;
}
*/

assetMan* GameEngine::getAssetMan()
{
	return m_assetMan;
}

void GameEngine::sUserInput()
{

	glfwPollEvents();
	//m_handler->processInput(m_renderer->getWindow());
}


/*aMap* GameEngine::getAM()
{
	return m_actionMap;
}*/

unsigned int GameEngine::getUniqueRID()
{
	return m_numRenderers++;
}	

void GameEngine::toggleOverlay()
{
	if(m_engineOverlay)
	{
		m_engineOverlay = false;
	}
	else
	{
		m_engineOverlay = true;
	}
}


std::string GameEngine::calcumalateFPS()
{
	std::string fps;
	auto now = std::chrono::steady_clock::now();
	std::chrono::duration<double> dt = now - m_fpsWindowStart;
	FPS_ = ((m_frameCount) / dt.count());
	m_fpsWindowStart = now;
	m_frameCount = 0;
	return fps = "FPS: " + std::to_string((unsigned int)FPS_);
}