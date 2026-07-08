#include "Entity.h"



template <typename T>
T & Entity::getComponent()
{
	return m_pool->getComponent<T>(m_ID);
}


template <typename T>
bool Entity::hasComponent()
{
	return m_pool->hasComponent<T>(m_ID);
}

template <typename T>
void Entity::remComponent()
{
	m_pool->remComponent<T>(m_ID);
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