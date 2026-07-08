#ifndef ENTITY_H
#define ENTITY_H
#include "EntityMemoryPool.h"




class Entity
{

	size_t m_ID;
	EntityMemoryPool* m_pool = nullptr;
	Entity();
	Entity(size_t id, EntityMemoryPool& pool) : m_ID(id), m_pool(&pool) {}
	friend class EntityMan;
	friend class EntityMemoryPool;
public:

	template <typename T>
	T & getComponent();

	template <typename T>
	bool hasComponent();

	template <typename T>
	void remComponent();

	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs);

	size_t getID() const;
	size_t getID();
};

#endif  // ENTITY_H