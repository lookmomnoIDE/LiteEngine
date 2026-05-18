#include "Scene_Play.h"
#include "GameEngine.h"


Scene_Play::Scene_Play(GameEngine* game, Renderer* renderer) 
	:m_game(game), m_renderer(renderer)
{
	Scene_Play::registerAction(GLFW_MOUSE_BUTTON_LEFT, "PLACE");
	Scene_Play::registerAction(GLFW_KEY_ESCAPE, "ESC");
}


void Scene_Play::init()
{
	
}

void Scene_Play::update()
{
	const EntityVec& entities = m_game->getEntityMan()->getEntities();
	const auto& pool = m_game->getPool();
	std::vector<bool> activeGravity = {};
	for ( const Entity& e : entities )
	{	
		const auto id = e.getID();
		//variable = (condition) ? expressionTrue : expressionFalse;
		if(!pool->hasComponent<Cgravity>(id)) continue;
		//activeGravity[id] = (pool->hasComponent<Cgravity>(id)) ? true : false;
		
		CTransform& transform = pool->getComponent<CTransform>(id);
		Cgravity& gravity = pool->getComponent<Cgravity>(id);
		auto& vel = transform.getVel();
		auto& pos = transform.getPos();
		vel[1] += gravity.getGravity();
		pos[1] += vel[1];
		if (pos[1] < -.9f)
		{
			pos[1] = -.9f;
			vel[0] = 0.0f;
			vel[1] = 0.0f;
			pool->remComponent<Cgravity>(id);
		}	
		
	}

/*	for ( const bool& b: activeGravity )
	{
		if(b)
		{
			CTransform& transform = pool->getComponent<CTransform>(id);
			Cgravity& gravity = pool->getComponent<Cgravity>(id);
			auto& vel = transform.getVel();
			auto& pos = transform.getPos();
			vel[1] += gravity.getGravity();
			pos[1] += vel[1];
			if (pos[1] < -.9f)
			{
				pos[1] = -.9f;
				vel[0] = 0.0f;
				vel[1] = 0.0f;
				pool->remComponent<Cgravity>(id);
			}
		}
		
	}*/

}


void Scene_Play::sAnimation()
{

}


void Scene_Play::sEnemySpawner()
{

}


void Scene_Play::sCollision()
{

}


void Scene_Play::sRender()
{
	m_renderer->Clear();
	EntityVec entities = m_game->getEntityMan()->getEntities();
	for ( Entity e : entities )
	{
		std::vector<float>& pos = m_game->getPool()->getComponent<CTransform>(e.getID()).getPos();
		m_renderer->Square(e, pos);
	}
	m_renderer->SwapBuffers();
}


void Scene_Play::sGUI()
{

}

bool Scene_Play::isPaused()
{
	return m_paused;
}

void Scene_Play::doAction(const Action& a)
{
	if (a.type() == "START")
	{
		if (a.name() == "PLACE")
		{
			m_primaryActionActive = true;
		}
	}
	if(a.type() == "END")
	{
		if(a.name() == "PLACE")
		{
			m_primaryActionActive = false;
		}
	}
	if (a.name() == "ESC")
	{
		m_game->quit();
	}
}

void Scene_Play::registerAction(int keycode, const std::string& aName)
{
	m_actionMap[keycode] = aName;
}

std::map<int, std::string>& Scene_Play::getAM()
{
	std::cout << "AM size: " << m_actionMap.size() << std::endl;
	return m_actionMap;
}

void Scene_Play::sDoAction()
{
	if (m_primaryActionActive)
	{
		glfwGetCursorPos(m_renderer->getWindow(), &m_x, &m_y);
		m_game->getFactory()->addSand(m_x, m_y);	
	}
}