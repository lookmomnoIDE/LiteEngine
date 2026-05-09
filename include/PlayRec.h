#ifndef PLAYREC_H
#define PLAYREC_H


class GameEngine;
class EntityFactory;

class PlayRec
{
	GameEngine* m_game = nullptr;
	EntityFactory* m_factory = nullptr;
public:
	PlayRec(GameEngine* game);
	~PlayRec();
	void placeSand(float x, float y);
};


#endif