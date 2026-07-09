#include "Scene_CGOL.h"
#include "GameEngine.h"
//#include "Tag.h"

#include <cmath>
#include <algorithm>

Vec4<float> visibleColor = {1.0f, 1.0f, 1.0f, 1.0f};
Vec4<float> invisibleColor = {1.0f, 1.0f, 1.0f, 0.0f};

Scene_CGoL::Scene_CGoL(GameEngine* game, Renderer* renderer, size_t maxEntities) 
	:Scene(game, renderer, maxEntities)//m_game(game), m_renderer(renderer), m_maxEntities(maxEntities)
{
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
	Vec4<float> visibleColor = {1.0f, 1.0f, 1.0f, 1.0f};
	Vec4<float> invisibleColor = {1.0f, 1.0f, 1.0f, 0.0f};



	m_quads.reserve((grid.m_Col * grid.m_Row));
	for (unsigned int j = 0; j < grid.m_Row; j++)
	{
		for(unsigned int i = 0; i < grid.m_Col; i++)
		{

			auto pos = grid.getCenterOfCell(Vec2<unsigned int>(i, j));
			auto q = GConstructor::rect(pos, invisibleColor, cSize);
			m_quads.push_back(q);
			m_factory.addCell(q, *this);
		}
	}

	m_renderer->addQuadBuffer(m_quads);

	std::cout << "End of init!" <<  std::endl;
}	

void Scene_CGoL::update()
{

	//Implement Rules
	//1. Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
	//
	//2. Any live cell with two or three live neighbours lives on to the next generation.
	//
	//3. Any live cell with more than three live neighbours dies, as if by overpopulation.
	//
	//4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
	for(size_t j = 0; j < grid.m_Row; j++)
	{
		for(size_t i = 0; i < grid.m_Col; i++)
		{

		}
	}







	Vec4<float> visibleColor = {1.0f, 1.0f, 1.0f, 1.0f};
	Vec4<float> invisibleColor = {1.0f, 1.0f, 1.0f, 0.0f};
	m_quads.clear();
	m_quads.reserve((grid.m_Col * grid.m_Row));
	for(size_t j = 0; j < grid.m_Row; j++)
	{
		for(size_t i = 0; i < grid.m_Col; i++)
		{
			auto currentState = grid.getState((unsigned int)j, (unsigned int)i);
			if(currentState == 1)
			{
				auto& cell = m_pool.getComponent<CCell>((size_t)((j*grid.m_Col) + i));
				cell.setColor(visibleColor); 
				Quad<float> quad = cell.getQuad();
				m_quads.push_back(quad);
			}
			else
			{
				continue;
			}
		}
	}
	m_renderer->updateQuadBuffer(1, m_quads);	
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

		auto size = grid.getCellSize();
		glfwGetCursorPos(m_renderer->getWindow(), &m_x, &m_y);		
		auto indexX = static_cast<unsigned int>(std::floor(m_x / size));
		auto indexY = static_cast<unsigned int>(std::floor(m_y / size));
		auto state = grid.getState(indexY, indexX);
		indexX = std::clamp(indexX, 0u, grid.getCols() - 1);
		indexY = std::clamp(indexY, 0u, grid.getRows() - 1);
		if (state == 0)
		{
			grid.setState(indexY, indexX, 1);		
		}
		else
		{
			grid.setState(indexY, indexX, 0);	
		}
		std::cout << "Primary Action Active!" << std::endl;
	}
}