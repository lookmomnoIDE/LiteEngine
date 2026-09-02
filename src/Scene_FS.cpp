#include "Scene_FS.h"
#include "GeometryConstructor.h"
#include "Kingdom.h"
#include "TKHelpers.h"
#include "Tags.h"
#include "GameEngine.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdexcept>

/*
struct UIArea
{
	Vec2<float> pos;
	Vec4<float> color;
	Vec2<float> dims;
	std::vector<Vec2<float>> texCoords;
};
*/

Scene_FS::Scene_FS(GameEngine* game, Renderer* renderer, size_t maxEntities) 
	:Scene(game, renderer, maxEntities)//m_game(game), m_renderer(renderer), m_maxEntities(maxEntities)
{
	Scene_FS::registerAction(GLFW_MOUSE_BUTTON_LEFT, "_LMB"); // Change place -> LMB
	Scene_FS::registerAction(GLFW_KEY_ESCAPE, "ESC");
	Scene_FS::registerAction(GLFW_KEY_P, "_P");
	Scene_FS::registerAction(GLFW_KEY_O, "_O");
	Scene_FS::registerAction(GLFW_KEY_SPACE, "SPACE");
	Scene_FS::registerAction(GLFW_KEY_F3, "_F3");
	m_assetMan = m_game->getAssetMan();
}


//C:\projects\LiteEngineV003\res\fonts\short
void Scene_FS::init()
{
	std::cout << "inside scene init" << std::endl;
	m_palette = m_assetMan->getPalette("colors");
	if(m_palette == nullptr)
	{
		std::cout << "m_palette not found" << std::endl;
	}
	Color color = m_palette->getColor("blue");
	Vec2<float> pos(0.0f, -0.75f);
	Vec2<float> dims(1.0f, 0.29f);
	std::vector<Vec2<float>> texCoords = std::vector<Vec2<float>>{Vec2<float>(1.0f, 0.0f), Vec2<float>(1.0f, 1.0f), Vec2<float>(0.0f, 0.0f), Vec2<float>(0.0f, 1.0f)};
	tQuad<float> tquad = GConstructor::tRect(pos, color, dims, texCoords);
	m_tQuads.push_back(tquad);
	Vec2<float> pos2 = Vec2<float>(0.0f, 0.98f);
	Vec2<float> dims2 = Vec2<float>(1.0f, 0.02f);
	tquad = GConstructor::tRect(pos2, color, dims2, texCoords);
	m_tQuads.push_back(tquad);
	m_renderer->initUIBuffer(sizeof(m_tQuads));
	m_renderer->updateUIBuffer(m_tQuads);

	unsigned int width, height;
	width = m_renderer->getWidth();
	height = m_renderer->getHeight() * .69;
	//Vec2<float> dims = {width, height};
	grid.setCellSize(10);
	grid.setLineWidth(4);
	grid.setColRow(width, height);
	m_quads = grid.fabGridLines(m_palette->getColor("black"),0.0f, 0.0f, 0.02f, 0.29f);
	m_renderer->initGridBuffer(grid.m_Col + grid.m_Row);
	m_renderer->updateGridBuffer(m_quads);
	m_quads.clear();


	unsigned int size = grid.getCellSize() - 1;
	Vec2<float> cSize = {(float)size/width*(width/height), (float)size/height};
	m_quads.reserve((grid.m_Col * grid.m_Row));
	for (unsigned int j = 0; j < grid.m_Row; j++)
	{
		for(unsigned int i = 0; i < grid.m_Col; i++)
		{
			auto pos = grid.getCenterOfCell(Vec2<unsigned int>(i, j));
			auto q = GConstructor::rect(pos, m_palette->getColor("black"), cSize);
			m_quads.push_back(q);
			m_factory.addCell(q, *this);
		}
	}
	m_renderer->initQuadBuffer(grid.m_Col * grid.m_Row);
	m_renderer->updateQuadBuffer(m_quads);
	std::cout << "scene initialized" << std::endl;
}


void Scene_FS::update()
{
	Quad<float> quad;
	if(!m_paused)
	{	
		
		if(m_frameCounter % 60 == 0)
		{

		}
		m_quads.clear();
		m_quads.reserve((grid.m_Col * grid.m_Row));

		for(size_t j = 0; j < grid.m_Row; j++)
		{
			for(size_t i = 0; i < grid.m_Col; i++)
			{
	
				auto currentState = grid.getState((unsigned int)j, (unsigned int)i);
				auto& cell = m_pool.getComponent<CCell>((size_t)((j*grid.m_Col) + i));
				switch(currentState)
				{
				case 0:
					cell.setColor(m_palette->getColor("black")); 
					quad = cell.getQuad();
					m_quads.push_back(quad);
				case 1:
					cell.setColor(m_palette->getColor("white")); 
					quad = cell.getQuad();
					m_quads.push_back(quad);
				}
			}
		}
		m_renderer->updateQuadBuffer(m_quads);
		m_frameCounter++;

	}
}


void Scene_FS::sAnimation()
{

}


void Scene_FS::sEnemySpawner()
{

}


void Scene_FS::sCollision()
{

}


void Scene_FS::sRender()
{
	m_renderer->Clear();
	m_assetMan->getTexture("default");
	m_renderer->drawGridBuffer();
	m_renderer->drawQuadBuffer();
	m_renderer->drawUIBuffer();
	if(m_paused)
	{
		m_renderer->drawText("Paused", ((1920.0/2.0f)-5.0f), ((1050.0f/2.0f)-20.0f), "IBM", 1.0f, m_palette->getColor("red")); 
	}
}


void Scene_FS::sGUI()
{

}


bool Scene_FS::isPaused()
{
	return m_paused;
}


void Scene_FS::doAction(const Action& a)
{
	if (a.type() == "START")
	{
		if (a.name() == "_LMB")
		{
			m_primaryActionActive = true;
		}

		if(a.name() == "SPACE")
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

		if(a.name() == "_F3")
		{
			m_game->toggleOverlay();
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


void Scene_FS::registerAction(int keycode, const std::string& aName)
{
	m_actionMap[keycode] = aName;
}


std::map<int, std::string>& Scene_FS::getAM()
{
	std::cout << "AM size: " << m_actionMap.size() << std::endl;
	return m_actionMap;
}


void Scene_FS::sDoAction()
{
	if (m_primaryActionActive)
	{
		auto size = grid.getCellSize();
		glfwGetCursorPos(m_renderer->getWindow(), &m_x, &m_y);		
		auto indexX = static_cast<unsigned int>(std::floor(m_x / size));
		auto indexY = static_cast<unsigned int>(std::floor(m_y / size));

		if((indexY < grid.m_Row && indexY >= 0) && (indexX < grid.m_Col && indexX >= 0))
		{
			auto state = grid.getState(indexY, indexX);
			if (state == 0)
			{
				grid.setState(indexY, indexX, 1);		
			}
			else
			{
				grid.setState(indexY, indexX, 0);	
			}	
		}
	}
}