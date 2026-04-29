#include "GameEngine.h"

void GameEngine::MainLoop()
{
	EntityManager.update()
	sUserInput();
	sMovement();
	sCollision();
	sRender();
	m_currentFrame++;
}

void GameEngine::spawnEnemy()
{
	auto e = EntityManager.addEntity("enemy");
}
