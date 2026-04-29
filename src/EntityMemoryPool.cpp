#include "EntityMemoryPool.h"
#include "Entity.h"

EntityMemoryPool::EntityMemoryPool(size_t MAX_ENTITIES)
    : m_MAX_ENTITIES(MAX_ENTITIES), m_numEntities(0)
{
    m_tags.resize(MAX_ENTITIES);
    m_active.resize(MAX_ENTITIES, false);
    std::get<std::vector<CTransform>>(m_pool).resize(MAX_ENTITIES);
    std::get<std::vector<Cgrain>>(m_pool).resize(MAX_ENTITIES);
}


EntityMemoryPool & EntityMemoryPool::Instance()
{
	static EntityMemoryPool pool(MAX_ENTITIES);
	return pool;
}

template <typename T>
T& EntityMemoryPool::getComponent(size_t entityID)
{
	return std::get<std::vector<T>>(m_pool)[entityID];
}

template <typename T>
bool EntityMemoryPool::hasComponent(size_t entityID)
{
	return std::get<std::vector<T>>(m_pool)[entityID].getActive();
}

template <typename T>
void EntityMemoryPool::remComponent(size_t entityID)
{
	std::get<std::vector<T>>(m_pool)[entityID] = T();
}


std::vector<bool> EntityMemoryPool::getActive()
{
	return m_active;
}


const std::string & EntityMemoryPool::getTag(size_t entityID) const
{
	return m_tags[entityID];
}

std::string & EntityMemoryPool::getTag(size_t entityID)
{
	return m_tags[entityID];
}

Entity EntityMemoryPool::addEntity(const std::string& tag)
{
	size_t index = getNextEntityIndex();

	m_tags[index] = tag;
	m_active[index] = true;
	m_numEntities++;
	return Entity(index);
}

size_t EntityMemoryPool::getNextEntityIndex()
{
	for(size_t i = 0; i < m_active.size(); i++)
	{
		if(!m_active[i])
		{
			return i;
		}
	}

}