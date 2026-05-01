#pragma once
#include "EntityManager.h"
#include "Entity.h"
#include "CTransform.h"
#include "Cgrain.h"
#include "Csand.h"
#include <vector>
#include <string>

class Entity;
static const size_t MAX_ENTITIES = 1000;

class EntityMemoryPool
{
public:
	typedef std::tuple<
	std::vector<CTransform>,
	std::vector<Cgrain>,
	std::vector<Csand>
	> EntityComponentVectorTuple;
private:
	size_t m_numEntities;
	EntityComponentVectorTuple m_pool;
	std::vector<std::string> m_tags;
	std::vector<bool> m_active;
	size_t m_MAX_ENTITIES;
	EntityMemoryPool(size_t MAX_ENTITIES);

public:
	static EntityMemoryPool & Instance();

	template <typename T>
	T& getComponent(size_t entityID)
	{
		return std::get<std::vector<T>>(m_pool)[entityID];
	}

	template <typename T>
	bool hasComponent(size_t entityID);

	template <typename T>
	void remComponent(size_t entityID);

	std::vector<bool> getActive();

	const std::string & getTag(size_t entityID) const;
	std::string & getTag(size_t entityID);

	Entity addEntity(const std::string& tag);

	size_t getNextEntityIndex();
};