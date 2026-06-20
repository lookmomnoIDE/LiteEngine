#include "Entity.h"
#include "EntityManager.h"
#include "EntityMemoryPool.h"



EntityMan* EntityMan::Instance()
{
	static EntityMan man{};
	return &man;
}

void EntityMan::update()
{
	for(auto& e : m_entitiesToAdd)
	{
		m_entities.push_back(e); 
		//m_entityMap[EntityMemoryPool::Instance().getTag(e.getID())].push_back(e);
	}
	m_entitiesToAdd.clear();
}

Entity EntityMan::addEntity(const Tag tag)
{
	Entity e = EntityMemoryPool::Instance()->addEntity(tag);
	m_entitiesToAdd.push_back(e);
	
	return e;
}

void EntityMan::remEntity(size_t index)
{
	std::vector<bool> active = EntityMemoryPool::Instance()->getActive();
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
		if(EntityMemoryPool::Instance()->getTag(e.getID()) == tag)
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