#include "includes.h"




int main(int argc, char* argv[])
{
	GameEngine::Instance();
	GameEngine::Instance()->Init();
	GameEngine::Instance()->run();
	return 0;
}



