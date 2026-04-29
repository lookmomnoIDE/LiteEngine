#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
//#include "Entity.h"
#include <map>
#include <vector>
#include <string>
#include "EntityMemoryPool.h"


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
	Entity addEntity(const std::string& tag);
	EntityVec& getEntities();
	EntityVec& getEntities(const std::string& tag);
	void remEntity(size_t index);
};

#endif //ENtityMan