#ifndef SCENE_H
#define SCENE_H


#include <string>
#include <map>
#include <memory>

#include "ICommand.h"
#include "EntityMemoryPool.h"
#include "EntityFactory.h"
#include "EntityManager.h"



class GameEngine;
class Renderer;
class assetMan;
class Palette;

class Scene 
{
public:
	int m_frame;
	bool m_paused = false;
	std::map<int, std::string> m_actionMap;
	GameEngine* m_game = nullptr;
	Renderer* m_renderer = nullptr;
	assetMan* m_assetMan = nullptr;
	Palette* m_palette;
	EntityMemoryPool m_pool; 
	EntityFactory m_factory;
    EntityMan m_entityManager;
    size_t m_maxEntities;

	Scene(GameEngine* game, Renderer* renderer, size_t maxEntities)
        : m_game(game), m_renderer(renderer), m_pool(maxEntities), m_entityManager(m_pool)
    {}
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
	EntityMemoryPool& getPool();
	EntityMan& getEntityMan();
};
#endif

//game->changeScene<Scene_Play>("play", LevelPath);