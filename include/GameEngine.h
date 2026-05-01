#include "EntityManager.h"
#include "Renderer.h"


EntityMan EntityManager;




class GameEngine
{
	unsigned int m_currentFrame = 0;

public:
	GameEngine();
	void MainLoop();
	void spawnEnemy();

};