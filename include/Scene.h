#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <map>
//#include "Command.h"

class GameEngine;


class Scene 
{
	
	int m_frame;
	//std::map<int i, std::string> m_actionMap;
	bool m_paused = false;
public:
	GameEngine* m_game = nullptr;
	virtual ~Scene() = default;
	virtual void init() = 0;
	virtual void update() = 0;
	//virtual void sDoAction(Command& c) = 0;
	virtual void sRender() = 0;
	virtual void simulate(int i) = 0;
	//virtual void doAction(Command& c) = 0;
	//virtual void registerAction(Command& c) = 0;
};
#endif

//game->changeScene<Scene_Play>("play", LevelPath);