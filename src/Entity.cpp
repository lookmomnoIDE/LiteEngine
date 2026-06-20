#include "Entity.h"



template <typename T>
T & Entity::getComponent()
{
	return EntityMemoryPool::Instance()->getComponent<T>(m_ID);
}


template <typename T>
bool Entity::hasComponent()
{
	return EntityMemoryPool::Instance()->hasComponent<T>(m_ID);
}

template <typename T>
void Entity::remComponent()
{
	EntityMemoryPool::Instance()->remComponent<T>(m_ID);
}

template <typename T, typename... TArgs>
T& Entity::addComponent(TArgs&&... mArgs)
{
	auto& component = std::get<T>();
	component = T(std::forward<TArgs>(mArgs)...);
	component.active = true;
	return component;
}


size_t Entity::getID() const 
{ 
	return m_ID;
}

size_t Entity::getID()  
{ 
	return m_ID;
}