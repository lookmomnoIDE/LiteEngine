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
	Grid g(m_renderer->getWidth(), m_renderer->getHeight(), 8, 2, 0);
	m_quads = g.fabGridLines();
	//m_quads = g.getGridLines();
	std::cout << "Grid initialized!" << std::endl;
	m_renderer->addQuadBuffer(m_quads);
	std::cout << "Grids added to buffer!" << std::endl;
}	

void Scene_CGoL::update()
{
	
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
	//m_renderer->getVB().Bind();
	//std::cout << "Pre draw call" << std::endl;
	m_renderer->DrawElements();
	//std::cout << "Post draw call" << std::endl;
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



