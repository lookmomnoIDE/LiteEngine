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


//C:\projects\LiteEngineV003\res\fonts\short
void Scene_test::init()
{
	std::cout << "inside scene test init fn" << std::endl;
	m_game->getAssetMan()->addFont("IBM", "fonts/short/Mx437_IBM_3270pc.ttf");
	std::cout << "after add font" << std::endl;
	
	//static Quad<T> tRect(Vec2<T> pos, Vec4<T> color, Vec2<T> dims, std::vector<Vec2<T>> texCoords)
	Vec2<float> pos = Vec2<float>(0.0f, 0.0f);
	Vec4<float> color = Vec4<float>(1.0f, 0.0f, 0.0f, 0.2f);
	Vec2<float> dims = Vec2<float>(0.5f, 0.5f);
	std::vector<Vec2<float>> texCoords = std::vector<Vec2<float>>{Vec2<float>(1.0f, 0.0f), Vec2<float>(1.0f, 1.0f), Vec2<float>(0.0f, 0.0f), Vec2<float>(0.0f, 1.0f)};
	tQuad<float> tquad = GConstructor::tRect(pos, color, dims, texCoords);
	m_tQuads.push_back(tquad);
	m_renderer->addQuadBufferT(m_tQuads);
	m_renderer->initTextBuffer(256);
}


void Scene_test::update()
{

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
	m_renderer->DrawElements("default");
	m_renderer->drawText("Hello, text!", 50.0f, 50.0f, "IBM", 1.0f);
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