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
	m_factory->addSand(x, y);
}	