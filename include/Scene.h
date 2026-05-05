#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <map>
#include "Command.h"
#include "GameEngine.h"
#include "EntityManager.h"


class Scene 
{
	GameEngine* m_game = nullptr;
	int m_frame;
	//std::map<int i, std::string> m_actionMap;
	bool m_paused;
public:
	virtual ~Scene() = default;
	virtual void init() = 0;

	virtual void update() = 0;
	virtual void sDoAction(Command& c);
	virtual void sRender();
	
	virtual void simulate(int i);
	virtual void doAction(Command& c);
	virtual void registerAction(Command& c);
};
#endif

//game->changeScene<Scene_Play>("play", LevelPath);