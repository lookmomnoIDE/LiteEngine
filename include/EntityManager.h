#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
//#include "Entity.h"
#include <map>
#include <vector>
#include <string>
#include <cstdint>
#include "EntityMemoryPool.h"
#include "Tags.h"


class Entity;

typedef std::vector<Entity> 				EntityVec;
typedef std::map<std::string, EntityVec> 	EntityMap;


class EntityMan
{
	EntityVec 	m_entities;
	EntityVec 	m_entitiesToAdd;
	EntityMap 	m_entityMap;
	size_t 		m_totalEntities = 0;
	
public:
	static EntityMan & Instance();
	void update();
	Entity addEntity(const Tag tag);
	EntityVec& getEntities();
	EntityVec& getEntities(const Tag tag);
	void remEntity(size_t index);
};

#endif //ENtityMan