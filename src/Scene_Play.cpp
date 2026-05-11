#include "Scene_Play.h"
#include "GameEngine.h"

Scene_Play::Scene_Play(GameEngine* game, Renderer* renderer) 
	:m_game(game), m_renderer(renderer)
{

}


/*void Scene_Play::init(GameEngine* game)
{
	m_game = game;
	m_renderer = &m_game->getRenderer();
}*/

void Scene_Play::update()
{
	EntityVec entities = m_game->getEntityMan()->getEntities();
	for ( Entity e : entities )
	{
		if(m_game->getPool()->hasComponent<Cgravity>(e.getID()))
		{
			CTransform& transform = m_game->getPool()->getComponent<CTransform>(e.getID());
			Cgravity& gravity = m_game->getPool()->getComponent<Cgravity>(e.getID());
			std::vector<float>& vel = transform.getVel();
			vel[1] += gravity.getGravity();
			std::vector<float>& pos = transform.getPos();
			pos[1] += vel[1];
			std::cout << "x: " << pos[0] << "y: " << pos[1] << std::endl;
			if (pos[1] < -.9)
			{
				pos[1] = -.9;
				vel[0] = 0;
				vel[1] = 0;
				m_game->getPool()->remComponent<Cgravity>(e.getID());
			}
			transform.setPos(pos);
			transform.setVel(vel);				
		}
		
	}
}
void Scene_Play::sAnimation()
{

}
void Scene_Play::sEnemySpawner()
{

}
void Scene_Play::sCollision()
{

}
void Scene_Play::sRender()
{
	m_renderer->Clear();
	EntityVec entities = m_game->getEntityMan()->getEntities();
	for ( Entity e : entities )
	{
		std::vector<float> pos = m_game->getPool()->getComponent<CTransform>(e.getID()).getPos();
		m_renderer->Square(e, pos);
	}
	m_renderer->SwapBuffers();
}
void Scene_Play::sDoAction()
{

}
void Scene_Play::sGUI()
{

}

bool Scene_Play::isPaused()
{
	return m_paused;
}
