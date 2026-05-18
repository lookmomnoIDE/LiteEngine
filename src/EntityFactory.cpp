#include "EntityFactory.h"
#include "GameEngine.h"


EntityFactory* EntityFactory::Instance()
{
	static EntityFactory factory{};
	//std::cout << factory << std::endl;
	return &factory;
}


void EntityFactory::Init()
{
	m_game = GameEngine::Instance();
}


void EntityFactory::addSand(double xpos, double ypos)
{
	int width = m_game->getRenderer()->getWidth();

	int height = m_game->getRenderer()->getHeight();

	const auto& pool = m_game->getPool();
	
	std::vector<float> pos = {(2.0f*xpos)/width - 1.0f, 1.0f - (2.0f*ypos)/height};
	
	std::vector<float> vel = {0.0f, 0.0f};
	
	Tag target = static_cast<Tag>(pool->getEnum("sand"));
	//Tag target = m_game->getPool().getEnum("sand");
	
	Entity e = m_game->getEntityMan()->addEntity(target); 
	
	size_t id = e.getID();
	// Add/set components
	
	pool->getComponent<CTransform>(id)	=	CTransform(pos, vel);
	
	pool->getComponent<Cgrain>(id)    	=	Cgrain();
	
	pool->getComponent<Csand>(id)	  	=	Csand();
	
	pool->getComponent<Cgravity>(id)  	=	Cgravity();
}
