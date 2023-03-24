#ifndef GAME_H_INCLUDE
#define GAME_H_INCLUDE

#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "Entity.h"
#include <iostream>
/*
* File: Game.h
* Date: 3/24/23
*
* This is the header file for the Game class. The Game class handles everything that occurs in the engine.
* The class handles what needs to happen. It is meant to connect entities to one another and command the renderer to clear the screen and display what needs to be rendered.
*/
class Game
{
private:
	int tickCounter;
	bool isRunning;
	SDL_Renderer* renderer;
	SDL_Window* window;

	SDL_Texture* texture;
	
	Entity* player;

public:
	Game();
	~Game();

	void init(const char* title, int xposition, int yposition, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	bool running();
	void clean();
};

#endif