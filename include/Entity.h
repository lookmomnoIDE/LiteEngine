#ifndef ENTITY_H
#define ENTITY_H
#include "EntityMemoryPool.h"



class Entity
{

	size_t m_ID;
	Entity();
	Entity(size_t id) : m_ID(id) {}
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