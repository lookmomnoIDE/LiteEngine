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
	
	Vec2<float> pos = {(2.0f*(float)xpos)/width - 1.0f, 1.0f - (2.0f*(float)ypos)/height};
	
	Vec2<float> vel = {0.0f, 0.0f};
	
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


void EntityFactory::addCell(Vec2<float> pos)
{
	//int width = m_game->getRenderer()->getWidth();

	//int height = m_game->getRenderer()->getHeight();

	const auto& pool = m_game->getPool();
	std::cout << "pool found!" << std::endl;
	//Vec2<float> pos = {(2.0f*(float)xpos)/width - 1.0f, 1.0f - (2.0f*(float)ypos)/height};
	
	
	Tag target = static_cast<Tag>(pool->getEnum("sand"));
	//Tag target = m_game->getPool().getEnum("sand");
	std::cout << "pre entity" << std::endl;
	Entity e = m_game->getEntityMan()->addEntity(target); 
	std::cout << "Entity added!" << std::endl;
	m_game->getEntityMan()->update();
	
	auto id = e.getID();
	std::cout << "entity ID: " << id << std::endl;
	// Add/set components
	

	/*std::cout << "about to construct temp" << std::endl;
	CTransform temp(pos);
	std::cout << "temp constructed" << std::endl;
	CTransform& ref = pool->getComponent<CTransform>(id);
	std::cout << "got ref from pool" << std::endl;
	ref = temp;
	std::cout << "assignment done" << std::endl;*/

	pool->getComponent<CTransform>(id)	=	CTransform(pos);
	std::cout << "transforms set" << std::endl;
	pool->getComponent<Cgrain>(id)    	=	Cgrain();
	
	pool->getComponent<Csand>(id)	  	=	Csand();
}