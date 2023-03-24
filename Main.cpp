#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"

Game* game = NULL;

int main(int argc, char* args[])
{
	//Variable deleration for the Frame Rate Limiter
	const int FPS = 60; //FPS is the target FPS
	const int frameDelay = 1000 / FPS;
	unsigned long long frameStart;
	int frameTime;

	//Initialize the Game class(This class is the driver of this project and EVERYTHING SHOULD go through it)
	//since keyword "new" is called !!!IT MUST BE DELETED BEFORE THE GAME CLOSES!!!
	game = new Game();
	game->init("DerfEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	//The game loop, this should continue untill the game class declares that the application should close
	//The game class has a variable that decides when this while loop should end
	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		//Check to see if the game should update
		//check to see if there is time that was not waited on
		//if true: the frame needs more time on screen so delay the difference
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();
	delete game;

	return 0;
}