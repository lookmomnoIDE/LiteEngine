#ifndef ENTITY_H
#define ENTITY_H
#include "EntityMemoryPool.h"




class Entity
{

	size_t m_ID;
	Entity();
	Entity(size_t id) : m_ID(id){}
	friend class EntityMan;
	friend class EntityMemoryPool;
public:
	size_t getID() const;
	size_t getID();
};

#endif  // ENTITY_H