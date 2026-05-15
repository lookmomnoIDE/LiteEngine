#ifndef ENTITYMEMORYPOOL_H
#define ENTITYMEMORYPOOL_H
#include "Components.h"
#include "EntityManager.h"
#include "Entity.h"
#include "CTransform.h"
#include "Cgrain.h"
#include "Csand.h"
#include "Cgravity.h"
#include "Tags.h"
#include <vector>
#include <string>
#include <cstdint>
#include <unordered_map>

class Entity;
static const size_t MAX_ENTITIES = 1000;

class EntityMemoryPool
{
public:
	typedef std::tuple<
	std::vector<CTransform>,
	std::vector<Cgrain>,
	std::vector<Csand>,
	std::vector<Cgravity>
	> EntityComponentVectorTuple;

private:
	size_t m_numEntities;
	EntityComponentVectorTuple m_pool;
	std::vector<Tag> m_tags;
	std::vector<bool> m_active;
	size_t m_MAX_ENTITIES;
	EntityMemoryPool(size_t MAX_ENTITIES);

public:
	static EntityMemoryPool* Instance();

	std::vector<bool>& getActive();

	template <typename T>
	T& getComponent(size_t entityID)
	{
		return std::get<std::vector<T>>(m_pool)[entityID];
	}

	template <typename T>
	bool hasComponent(size_t entityID)
	{

		auto& componentVec = std::get<std::vector<T>>(m_pool);
	    return componentVec[entityID].isActive();
		/*bool active = std::get<std::vector<T>>(m_pool)[entityID].isActive();
		return active;*/
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
};



#endif