#include "SpawnSand.h"
#include "GameEngine.h"

SpawnSand::SpawnSand(PlayRec *rec, GameEngine* game)
	:m_rec(rec), m_game(game)
{

}

void SpawnSand::execute()  
{
	std::cout << "SpawnSand execute fn" << std::endl;
	//std::vector<double> pos = m_game->getHandler()->getMousePosition();
	glfwGetCursorPos(m_game->getRenderer()->getWindow(), &m_xpos, &m_ypos);
	m_rec->placeSand(m_xpos, m_ypos);
}


void SpawnSand::unexecute() const
{
	std::cout << "Stopping!" << std::endl;
}