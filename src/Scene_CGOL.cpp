#include "Scene_Play.h"
#include "GameEngine.h"
//#include "Tag.h"
#include "Vec2.h"


Scene_Play::Scene_Play(GameEngine* game, Renderer* renderer) 
	:m_game(game), m_renderer(renderer)
{
	Scene_Play::registerAction(GLFW_MOUSE_BUTTON_LEFT, "PLACE"); // Change place -> LMB
	Scene_Play::registerAction(GLFW_KEY_ESCAPE, "ESC");
}


void Scene_Play::init()
{
	//Initialize quads in memory
	
	const auto& pool = m_game->getPool();
	auto ME = pool->getMaxEnts();
	m_quads.reserve(ME);
	std::cout << "Pre scene init loop" << std::endl;
	const EntityVec& entities = m_game->getEntityMan()->getEntities();
	for (const Entity& e : entities)
	{
		auto id = e.getID();
		pool->getComponent<Cgrain>(id).createQuad(pool->getComponent<CTransform>(id).getPos(), pool->getComponent<Csand>(id).getColor());
	}
	
}	

void Scene_Play::update()
{
	//m_quads.clear();
	const EntityVec& entities = m_game->getEntityMan()->getEntities();
	const auto& pool = m_game->getPool();
	//std::vector<Quad> m_quads;
	std::cout << "entering scene update fn" << std::endl;
	
	//update transform positions. 
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
		vel.m_y += gravity.getGravity();;
		pos.m_y += vel.m_y;
		if (pos.m_y < -.9f)
		{
			pos.m_y = -.9f;
			vel.m_x = 0.0f;
			vel.m_y = 0.0f;
			pool->remComponent<Cgravity>(id);
		}	
		
	}
	std::cout << "transforms" << std::endl;
	//update quad positions
	for(const Entity& e: entities)
	{
		//update quad positions. 
		const auto 		id 			= e.getID();
		CTransform& 	transform 	= pool->getComponent<CTransform>(id);
		Cgrain& 		grain 		= pool->getComponent<Cgrain>(id);
		Csand& 			sand 		= pool->getComponent<Csand>(id);
		//auto& 			pos 		= transform.getPos();
		grain.setQuadPos(transform.getPos());	
		if (sand.colorDirty)
		{
			grain.setQuadColor(sand.getColor());
			sand.colorDirty = false;
		}

	}
	std::cout << "quad positions set" << std::endl;
	//add quads to vector of quads
	m_quads.clear();
	for(const Entity& e :entities)
	{
		auto id = e.getID();
		Cgrain& grain = pool->getComponent<Cgrain>(id);
		m_quads.push_back(grain.getQuad());
	}
	std::cout << "Quad buffer set" << std::endl;
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

	if (!m_quads.empty())
    {
        auto& q = m_quads[0];
        std::cout << "v0: " << q.v0.Position.m_x << ", " << q.v0.Position.m_y << ", " << q.v0.Position.m_z << std::endl;
        std::cout << "v1: " << q.v1.Position.m_x << ", " << q.v1.Position.m_y << ", " << q.v1.Position.m_z << std::endl;
        std::cout << "v2: " << q.v2.Position.m_x << ", " << q.v2.Position.m_y << ", " << q.v2.Position.m_z << std::endl;
        std::cout << "v3: " << q.v3.Position.m_x << ", " << q.v3.Position.m_y << ", " << q.v3.Position.m_z << std::endl;
        std::cout << "color: " << q.v0.Color.m_x << ", " << q.v0.Color.m_y << ", " << q.v0.Color.m_z << ", " << q.v0.Color.m_w << std::endl;
    }
	m_renderer->Clear();
	m_renderer->getVB().Bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0, m_game->getPool()->getMaxEnts() * sizeof(Quad), m_quads.data());
	m_renderer->DrawElements();
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
		std::cout << "placed some sand!" << std::endl;
	}
}



