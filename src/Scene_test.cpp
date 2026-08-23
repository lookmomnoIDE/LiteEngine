#include "Scene_test.h"
#include "GameEngine.h"
//#include "Tag.h"

#include <cmath>
#include <algorithm>
#include <stdexcept>


Scene_test::Scene_test(GameEngine* game, Renderer* renderer, size_t maxEntities) 
	:Scene(game, renderer, maxEntities)//m_game(game), m_renderer(renderer), m_maxEntities(maxEntities)
{
	Scene_test::registerAction(GLFW_MOUSE_BUTTON_LEFT, "_LMB"); // Change place -> LMB
	Scene_test::registerAction(GLFW_KEY_ESCAPE, "ESC");
	Scene_test::registerAction(GLFW_KEY_P, "_P");
	Scene_test::registerAction(GLFW_KEY_O, "_O");
}




//C:\projects\LiteEngineV003\res/fonts/oldschool_pc_font_pack_v2.2_win/ttf - Mx (mixed outline+bitmap)/Mx437_IBM_3270pc.ttf
void Scene_test::init()
{
	std::cout << "inside scene test init fn" << std::endl;
	m_game->getAssetMan()->addFont("IBM", "../res/fonts/oldschool_pc_font_pack_v2.2_win/ttf - Mx (mixed outline+bitmap)/Mx437_IBM_3270pc.ttf");
	std::cout << "after add font" << std::endl;
}	

void Scene_test::update()
{
	std::cout << "inside scene test update loop" << std::endl;
	//void Renderer::RenderText(std::string text, float x, float y, std::string fontName, float scale = 1)
	m_renderer->RenderText("Hello, text!", 0.0f, 0.0f, "IBM", 1.0f);
	
}


void Scene_test::sAnimation()
{

}


void Scene_test::sEnemySpawner()
{

}


void Scene_test::sCollision()
{

}


void Scene_test::sRender()
{
	m_renderer->Clear();
	m_renderer->DrawElements();
	m_renderer->SwapBuffers();
}


void Scene_test::sGUI()
{

}

bool Scene_test::isPaused()
{
	return m_paused;
}

void Scene_test::doAction(const Action& a)
{
	if (a.type() == "START")
	{
		if (a.name() == "_LMB")
		{
			m_primaryActionActive = true;
		}
		if(a.name() == "_P")
		{
			if(m_paused == false)
			{
				m_paused = true;
			}
			else
			{
				m_paused = false;
			}
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
		glfwSetWindowShouldClose(m_renderer->getWindow(), true);
		m_game->quit();
	}
}

void Scene_test::registerAction(int keycode, const std::string& aName)
{
	m_actionMap[keycode] = aName;
}

std::map<int, std::string>& Scene_test::getAM()
{
	std::cout << "AM size: " << m_actionMap.size() << std::endl;
	return m_actionMap;
}

void Scene_test::sDoAction()
{
	if (m_primaryActionActive)
	{
		
	}
}