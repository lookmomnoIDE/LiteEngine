#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <map>
#include "Command.h"
#include "GameEngine.h"
#include "EntityManager.h"


class Scene 
{
	GameEngine* m_game;
	EntityMan* m_entities;
	int m_frame;
	map<int, std::string> m_actionMap;
	bool m_paused;
public:

	void update();
	void sDoAction(Command c);
	void sRender();

	void simulate(int i);
	void doAction(Command c);
	void registerAction(Command c);
};
#endif

//game->changeScene<Scene_Play>("play", LevelPath);