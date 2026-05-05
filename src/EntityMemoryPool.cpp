#include "EntityMemoryPool.h"
#include "Entity.h"

EntityMemoryPool::EntityMemoryPool(size_t MAX_ENTITIES)
    : m_MAX_ENTITIES(MAX_ENTITIES), m_numEntities(0)
{
    std::get<std::vector<CTransform>>(m_pool).resize(m_MAX_ENTITIES);
    std::get<std::vector<Cgrain>>(m_pool).resize(m_MAX_ENTITIES);
    std::get<std::vector<Csand>>(m_pool).resize(m_MAX_ENTITIES);
    std::get<std::vector<Cgravity>>(m_pool).resize(m_MAX_ENTITIES);
    m_tags.resize(m_MAX_ENTITIES);
	m_active.resize(m_MAX_ENTITIES, false);
}


EntityMemoryPool & EntityMemoryPool::Instance()
{
	static EntityMemoryPool pool(MAX_ENTITIES);
	return pool;
}

/*template <typename T>
T& EntityMemoryPool::getComponent(size_t entityID)
{
	return std::get<std::vector<T>>(m_pool)[entityID];
}*/



/*template <typename T>
void EntityMemoryPool::remComponent(size_t entityID)
{
	std::get<std::vector<T>>(m_pool)[entityID] = T();
}
*/

std::vector<bool>& EntityMemoryPool::getActive()
{
	return m_active;
}


const Tag& EntityMemoryPool::getTag(size_t entityID) const
{
	return m_tags[entityID];
}

Tag& EntityMemoryPool::getTag(size_t entityID)
{
	return m_tags[entityID];
}

bool EntityMemoryPool::hasTag(size_t entityID, Tag tag) const
{
	if (m_tags[entityID] == tag)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

Entity EntityMemoryPool::addEntity(const Tag tag)
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

int EntityMemoryPool::getEnum(std::string s)
{
    static const std::unordered_map<std::string, uint8_t> tagMap = {
        {"grain", 0}, {"sand", 1}, {"gravity", 2}  // your actual tags
    };
    auto it = tagMap.find(s);
    return (it != tagMap.end()) ? it->second : 255; // 255 = not found
}