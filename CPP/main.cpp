#include "ExampleGame.h"
#include "MathUtils.h"
#include <iostream>


using namespace std;

int main(int argc, char* argv[])
{
	ExampleGame* game = new ExampleGame();
	game->InitSDL();
//	game->InitTestImage();

	game->Run();

	game->Clean();


	return 0;
}