#include "GameEngine.h"



GameEngine* GameEngine::Instance()
{
	static GameEngine instance{};
	//std::cout << &instance << std::endl;
	return &instance;
}


GameEngine::~GameEngine()
{
	delete m_renderer;
	//m_renderer = nullptr;


}


void GameEngine::Init()
{

	m_running = true;


	m_renderer = new Renderer();
	m_renderer->Init();
	m_scenes["play"] = std::make_unique<Scene_Play>(this, m_renderer);
	m_scenes["CGoL"] = std::make_unique<Scene_CGoL>(this, m_renderer);
	m_factory->Init();
	InputHandler::Instance();
	InputHandler::Instance().Init();
	
}


void GameEngine::update()
{

}


void GameEngine::run()
{
	double currentTime, elapsedTime;
	//m_renderer->CGoLMemory();
	changeScene<Scene_CGoL>("CGoL", m_renderer);
	
	//These two lines of code handle memory setup and scene deployment of the falling sand demo. 
	//m_renderer->fallingSandMemory();
	//changeScene<Scene_Play>("play", m_renderer);
	while(m_running)
	{
		currentTime = glfwGetTime();
		m_entityMan->update();
		GameEngine::sUserInput();
		
		currentScene()->update();
		std::cout << "Pre render loop" << std::endl;
        currentScene()->sRender();
        std::cout << "Post render loop" << std::endl;


        currentScene()->sDoAction();
        m_currentFrame++;
        double elapsedTime = glfwGetTime();
        double dt = elapsedTime - currentTime;
        double FPS_ = (double)m_currentFrame/dt;
        m_currentFrame = 0;
        std::cout << "FPS: " << FPS_ << std::endl;
        //std::cout << "Total entities: " << EntityMemoryPool::Instance()->getNumEntities() << std::endl;
		//std::cout << m_currentFrame << std::endl;
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


EntityFactory* GameEngine::getFactory()
{
	return m_factory;
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