#include "Scene.h"
#include "GameEngine.h"
#include "Renderer.h"
#include "assetManager.h"



/*virtual void Scene::init()
{
	//registerAction()
}

virtual void Scene::update()
{
	//EntityVec& currentEntities = entityMan.getEntities();
}

virtual void Scene::sDoAction(Command c)
{

}

virtual void Scene::sRender()
{

}

virtual void Scene::simulate(int i)
{

}

virtual void Scene::doAction(Command c)
{

}

virtual void Scene::registerAction()
{
	//m_actionMap[c] = name;
}*/

EntityMemoryPool& Scene::getPool()
{
	return m_pool;
}

EntityMan& Scene::getEntityMan()
{
	return m_entityManager;
}