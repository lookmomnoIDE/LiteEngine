#include "includes.h"





int main(int argc, char* argv[])
{
	auto g = std::make_unique<GameEngine>();
	g->run();
	return 0;
}



