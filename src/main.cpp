#include "includes.h"


GameEngine g;


int main(int argc, char* argv[])
{
	g.run();
	g.getRenderer().~Renderer();
	return 0;
}



