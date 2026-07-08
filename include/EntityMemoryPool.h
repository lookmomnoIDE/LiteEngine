#ifndef ENTITYMEMORYPOOL_H
#define ENTITYMEMORYPOOL_H
#include "Components.h"
#include "EntityManager.h"
#include "Entity.h"
#include "CTransform.h"
#include "Cgrain.h"
#include "Csand.h"
#include "Cgravity.h"
#include "CCell.h"
#include "Tags.h"


#include <vector>
#include <string>
#include <cstdint>
#include <unordered_map>


class Entity;
//static const size_t MAX_ENTITIES = 15000;

class EntityMemoryPool
{
public:
	typedef std::tuple<
	std::vector<CTransform>,
	std::vector<Cgrain>,
	std::vector<Csand>,
	std::vector<Cgravity>,
	std::vector<CCell>
	> EntityComponentVectorTuple;

private:
	size_t m_numEntities;
	EntityComponentVectorTuple m_pool;
	std::vector<Tag> m_tags;
	std::vector<bool> m_active;
	size_t m_MAX_ENTITIES;
	size_t m_lastIndex = 0;
	

public:
	EntityMemoryPool(size_t MAX_ENTITIES);
	//static EntityMemoryPool* Instance();

	std::vector<bool>& getActive();

	template <typename T>
	T& getComponent(size_t entityID)
	{
		return std::get<std::vector<T>>(m_pool)[entityID];
	}

	template <typename T>
	std::vector<T>& getComponentVector()
	{
		return std::get<std::vector<T>>(m_pool);
	}

	template <typename T>
	bool hasComponent(size_t entityID)
	{
		auto& componentVec = std::get<std::vector<T>>(m_pool);
	    return componentVec[entityID].isActive();
	}
	template <typename T>
	void remComponent(size_t entityID)
	{
		std::get<std::vector<T>>(m_pool)[entityID].setActive(false);
	}

	template <typename T>
	void addComponent(size_t entityID)
	{
		std::get<std::vector<T>>(m_pool)[entityID].setActive(true);
	}


	const Tag& getTag(size_t entityID) const;
	Tag& getTag(size_t entityID);
	bool hasTag(size_t entityID, Tag tag) const;

	Entity addEntity(const Tag tag);

	size_t getNextEntityIndex();

	int getEnum(std::string s);

	size_t getNumEntities();

	size_t getMaxEnts();
};



#endif