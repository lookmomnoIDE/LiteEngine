#include "Entity.h"
#include "EntityManager.h"
#include "EntityMemoryPool.h"


EntityMan::EntityMan(EntityMemoryPool& pool)
:m_pool(&pool)
{

}
/*EntityMan* EntityMan::Instance()
{
	static EntityMan man{};
	return &man;
}*/

void EntityMan::update()
{
	for(auto& e : m_entitiesToAdd)
	{
		m_entities.push_back(e); 
		//m_entityMap[m_pool.getTag(e.getID())].push_back(e);
	}
	m_entitiesToAdd.clear();
}

Entity EntityMan::addEntity(const Tag tag)
{
	Entity e = m_pool->addEntity(tag);
	m_entitiesToAdd.push_back(e);
	
	return e;
}

void EntityMan::remEntity(size_t index)
{
	std::vector<bool> active = m_pool->getActive();
	active[index] = false;
}


EntityVec& EntityMan::getEntities()
{
	return m_entities;
}

EntityVec& EntityMan::getEntities(const Tag tag)
{
	
	for(auto& e : m_entities)
	{
		if(m_pool->getTag(e.getID()) == tag)
		{
			m_entitiesByTag.push_back(e);
		}
	}
	return m_entitiesByTag;
}


size_t EntityMan::getTotalEntities()
{
	return m_totalEntities;
}