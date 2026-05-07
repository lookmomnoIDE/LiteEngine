#include "EntityFactory.h"


EntityFactory::EntityFactory(GameEngine* game)
	:m_game(game)
	{

	}


void EntityFactory::addSand(double xpos, double ypos)
{
	float width = m_game->getRenderer().getWidth();
	float height = m_game->getRenderer().getHeight();
	std::vector<float> pos = {(2.0f*xpos)/width - 1.0f, 1.0f - (2.0f*ypos)/height};
	std::vector<float> vel = {0.0f, 0.0f};
	Tag target = static_cast<Tag>(m_game->getPool().getEnum("sand"));
	//Tag target = m_game->getPool().getEnum("sand");
	Entity e = m_game->getEntityMan().addEntity(target); // wants tag
	size_t id = e.getID();
	// Add/set components
	m_game->getPool().getComponent<CTransform>(id)	=	CTransform(pos, vel);
	m_game->getPool().getComponent<Cgrain>(id)    	=	Cgrain();
	m_game->getPool().getComponent<Csand>(id)	  	=	Csand();
	m_game->getPool().getComponent<Cgravity>(id)  	=	Cgravity();
}
