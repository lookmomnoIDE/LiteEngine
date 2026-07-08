#include "Scene_CGOL.h"
#include "GameEngine.h"
//#include "Tag.h"



Scene_CGoL::Scene_CGoL(GameEngine* game, Renderer* renderer, size_t maxEntities) 
	:Scene(game, renderer, maxEntities)//m_game(game), m_renderer(renderer), m_maxEntities(maxEntities)
{
	//m_pool(m_maxEntities);
	//m_entityManager(m_pool);
	Scene_CGoL::registerAction(GLFW_MOUSE_BUTTON_LEFT, "_LMB"); // Change place -> LMB
	Scene_CGoL::registerAction(GLFW_KEY_ESCAPE, "ESC");
}


void Scene_CGoL::init()
{
	unsigned int width, height;
	width = m_renderer->getWidth();
	height = m_renderer->getHeight();
	Vec2<float> dims = {width, height};
	grid.setCellSize(10);
	grid.setLineWidth(4);
	grid.setColRow(width, height);
	m_quads = grid.fabGridLines();
	m_renderer->addQuadBuffer(m_quads);
	m_quads.clear();

	auto ME = m_pool.getMaxEnts();
	unsigned int size = grid.getCellSize() - 1;
	Vec2<float> cSize = {(float)size/width*(width/height), (float)size/height};
	Vec4<float> color = {1.0f, 1.0f, 1.0f, 1.0f};



	m_quads.reserve(120*65*sizeof(Quad<float>));
	for (unsigned int i = 0; i < grid.m_Col; i++)
	{
		for(unsigned int j = 0; j < grid.m_Row; j++)
		{
			std::cout << "inside factory loop (Cell: " << i << ", " << j << ")" << std::endl;
			auto pos = grid.getCenterOfCell(Vec2<unsigned int>(i, j));
			//auto pos = GConstructor::normalize(grid.getCenterOfCell(Vec2<unsigned int>(j, i)), dims);
			auto q = GConstructor::rect(pos, color, cSize);
			m_quads.push_back(q);
			m_factory.addCell(q, *this);
			std::cout << "added cell: " << i << ", " << j << " at " << pos.m_x << ", " << pos.m_y << std::endl;
		}
	}

	m_renderer->addQuadBuffer(m_quads);

	std::cout << "End of init!" <<  std::endl;
}	

void Scene_CGoL::update()
{
	for(unsigned int i = 0; i < grid.m_Col; i++)
	{
		for(unsigned int j = 0; j < grid.m_Row; j++)
		{
			m_quads.push_back(m_pool.getComponent<CCell>((size_t)(i+j)).getQuad());
		}
	}
	m_renderer->updateQuadBuffer(1, m_quads);
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


