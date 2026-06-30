#include "Scene_CGOL.h"
#include "GameEngine.h"
//#include "Tag.h"
#include "Vec2.h"
#include "Grid.h"


Scene_CGoL::Scene_CGoL(GameEngine* game, Renderer* renderer) 
	:m_game(game), m_renderer(renderer)
{
	Scene_CGoL::registerAction(GLFW_MOUSE_BUTTON_LEFT, "_LMB"); // Change place -> LMB
	Scene_CGoL::registerAction(GLFW_KEY_ESCAPE, "ESC");
}


void Scene_CGoL::init()
{
	Grid g(m_renderer->getWidth(), m_renderer->getHeight(), 20, 4, 0);
	m_quads = g.fabGridLines();
	m_renderer->addQuadBuffer(m_quads);
	//m_quadsList.push_back(m_quads);
	//m_renderer->addQuadBuffer(m_quads);
	m_quads.clear();

	const auto& pool = m_game->getPool();
	auto ME = pool->getMaxEnts();
	auto factory = m_game->getFactory();
	//m_quads.reserve(ME);
	for (auto i = 0; i < ME; i++)
	{
		/*Tag target = static_cast<Tag>(pool->getEnum("sand"));
		Entity e = m_game->getEntityMan()->addEntity(target); 
		std::cout << "added a entity" << std::endl;*/
		std::cout << "inside factory loop (iter: " << i << ")" << std::endl;
		factory->addCell(g.getCenterOfCell((size_t)i));
		std::cout << "added cell: " << i << std::endl;
	}

	//std::cout << "Pre scene init loop" << std::endl;
	//m_game->getEntityMan()->update();
	EntityVec& entities = m_game->getEntityMan()->getEntities();
	std::cout << "# of Entities: " << entities.size() << std::endl;
/*	for ( auto e : entities)
	{
		std::cout << "1. inside CTransform loop" << std::endl;
		auto id = e.getID();
		std::cout << "ID set: " << id << std::endl;
		pool->getComponent<CTransform>(id).setPos(g.getCenterOfCell(id));
		std::cout << "inside CTransform loop" << std::endl;
	}*/

	for ( auto e : entities)
	{
		std::cout << "1. inside grain loop" << std::endl;
		auto id = e.getID();
		m_quads.push_back(pool->getComponent<Cgrain>(id).createQuad(pool->getComponent<CTransform>(id).getPos(), pool->getComponent<Csand>(id).getColor()));
		std::cout << "inside grain loop" << std::endl;
	}
	//m_quadsList.push_back(m_quads);
	m_renderer->addQuadBuffer(m_quads);
	m_quads.clear();
	/*for (auto i : m_quadsList)
	{
		m_renderer->addQuadBuffer(m_quadsList[i]);
	}*/
	/*for (size_t i = 0; i < m_quadsList.size(); ++i) 
	{
    	m_renderer->addQuadBuffer(m_quadsList[i]);
	}*/

	std::cout << "End of init!" <<  std::endl;
}	

void Scene_CGoL::update()
{
	m_quads.clear();
	const EntityVec& entities = m_game->getEntityMan()->getEntities();
	const auto& pool = m_game->getPool();
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
		m_quads.push_back(grain.getQuad());

	}
	m_renderer->addQuadBuffer( m_quads);
	m_quads.clear();
}


void Scene_CGoL::sAnimation()
{

}


void Scene_CGoL::sEnemySpawner()
{

}


void Scene_CGoL::sCollision()
{

}


void Scene_CGoL::sRender()
{
	m_renderer->Clear();
	m_renderer->DrawElements();
	m_renderer->SwapBuffers();
}


void Scene_CGoL::sGUI()
{

}

bool Scene_CGoL::isPaused()
{
	return m_paused;
}

void Scene_CGoL::doAction(const Action& a)
{
	if (a.type() == "START")
	{
		if (a.name() == "_LMB")
		{
			m_primaryActionActive = true;
		}
	}
	if(a.type() == "END")
	{
		if(a.name() == "_LMB")
		{
			m_primaryActionActive = false;
		}
	}
	if (a.name() == "ESC")
	{
		m_game->quit();
	}
}

void Scene_CGoL::registerAction(int keycode, const std::string& aName)
{
	m_actionMap[keycode] = aName;
}

std::map<int, std::string>& Scene_CGoL::getAM()
{
	std::cout << "AM size: " << m_actionMap.size() << std::endl;
	return m_actionMap;
}

void Scene_CGoL::sDoAction()
{
	if (m_primaryActionActive)
	{

		//glfwGetCursorPos(m_renderer->getWindow(), &m_x, &m_y);
		//m_game->getFactory()->addSand(m_x, m_y);	
		std::cout << "Primary Action Active!" << std::endl;
	}
}



