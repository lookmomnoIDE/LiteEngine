#include "SpawnSand.h"
#include "GameEngine.h"

LMB_::LMB_(GameEngine* game)
	:m_game(game)
{

}

void LMB_::execute()  
{
	/*glfwGetCursorPos(m_game->getRenderer()->getWindow(), &m_xpos, &m_ypos);
	m_rec->placeSand(m_xpos, m_ypos);*/	
	//m_spawning = true;
	
}


void LMB_::unexecute() 
{
	//m_spawning = false;
}

bool isSpawning()
{
	return m_spawning;
}