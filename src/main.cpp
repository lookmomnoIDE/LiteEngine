#include "includes.h"





int main(int argc, char* argv[])
{
	GameEngine::Instance();
	GameEngine::Instance()->Init();
	GameEngine::Instance()->run();
	/*auto g = std::make_unique<GameEngine>();
	g->run();*/
	return 0;
}



