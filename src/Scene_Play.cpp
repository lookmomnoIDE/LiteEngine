#include "Scene_Play.h"


void init()
{

}

void update()
{
	for ( Entity e : m_entities )
	{
		if(m_game->getPool().hasComponent<Cgravity>(e.getID()))
		{
			CTransform& transform = m_game->getPool().getComponent<CTransform>(e.getID());
			Cgravity& gravity = m_game->getPool().getComponent<Cgravity>(e.getID());
			std::vector<float>& vel = transform.getVel();
			vel[1] += gravity.getGravity();
			std::vector<float>& pos = transform.getPos();
			pos[1] += vel[1];
			std::cout << "x: " << pos[0] << "y: " << pos[1] << std::endl;
			if (pos[1] <= -1)
			{
				pos[1] = -.9;
				vel[0] = 0;
				vel[1] = 0;
				m_game->getPool().remComponent<Cgravity>(e.getID());
			}
			transform.setPos(pos);
			transform.setVel(vel);				
		}
		
	}
}
void sAnimation()
{

}
void sEnemySpawner()
{

}
void sCollision()
{

}
void sRender()
{
	m_game->getRenderer().clear();
	for ( Entity e : m_entities )
	{
		std::vector<float> pos = pool.getComponent<CTransform>(e.getID()).getPos();
		renderer.Square(e, pos);
	}
	m_game->getRenderer().swapBuffers();
}
void sDoAction()
{

}
void sGUI()
{

}
