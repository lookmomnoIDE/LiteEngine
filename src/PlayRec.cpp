#include "PlayRec.h"
#include "GameEngine.h"
#include "EntityFactory.h"


PlayRec::PlayRec(GameEngine* game)
	:m_game(game)
{
	m_factory = m_game->getFactory();
}
PlayRec::~PlayRec()
{

}
void PlayRec::placeSand(float x, float y)
{
	std::cout << "Reciver fn" << std::endl;
	m_factory->addSand(x, y);
	std::cout << "after addSand in rc fn" << std::endl;
}	