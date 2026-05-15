#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <map>

#include "ICommand.h"

class GameEngine;
class Renderer;


class Scene 
{
public:
	int m_frame;
	bool m_paused = false;
	std::map<int, std::string> m_actionMap;
	Scene(){}
    virtual void init() = 0;
	virtual ~Scene() = default;
	//virtual void init(GameEngine* game) = 0;
	virtual void update() = 0;
	virtual void sDoAction() = 0;
	virtual void sRender() = 0;
	//virtual void simulate(int i) = 0;
	virtual void doAction(const Action& c) = 0;
	virtual void registerAction(int keycode, const std::string& aName) = 0;
	virtual std::map<int, std::string>& getAM() = 0;
};
#endif

//game->changeScene<Scene_Play>("play", LevelPath);