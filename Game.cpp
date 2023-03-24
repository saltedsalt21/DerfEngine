#include "Game.h"
/*
* File: Game.ccp
* Date: 3/24/23
*
* This is the cpp file for the Game class. contains definitions for Game class functions
*/
Game::Game()
{
	tickCounter = 0;
	isRunning = NULL;
	window = nullptr;
	renderer = nullptr;

	texture = nullptr;
	player = nullptr;
}
Game::~Game()
{
	std::cout << std::endl << "!!!GAME CLASS DELETED!!!" << std::endl;

	delete player;
}
/* ========================
*	Function: init(...)
*	This function initializes the renderer, window, and required entities.
*	Calls the SDL initialization functions
*/// ======================
void Game::init(const char* title, int xposition, int yposition, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Subsystems Initialized..." << std::endl;

		window = SDL_CreateWindow(title, xposition, yposition, width, height, flags);
		if (window)
		{
			std::cout << "Window created..." << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		TextureManager::setRenderer(renderer);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created..." << std::endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	player = new Entity("assets/LittleGuy.png", 0, 0, 32, 32, 1.5, 0.5);
}
/* ========================
*	Function: handleEvents()
*	This function handles the window events and allows entities to process user input
*	Checks to see if the user wants to quit via alt+F4 or the window close button and after triggers entity event handler
*/// ======================
void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default: break;
	}

	player->handleEntityEvents(event);
}
/* ========================
*	Function: update()
*	Function to trigger entities to update positions and process need calculations
*/// ======================
void Game::update()
{
	tickCounter++;
	std::cout << tickCounter << std::endl;
	player->entityUpdate();
}
/* ========================
*	Function: render()
*	Function to clear the screen and then call entities to send textures to the TextureManager to render then finally display everything that was processed
*/// ======================
void Game::render()
{
	SDL_RenderClear(renderer);
	//Add stuff here that is needed to be rendered
	player->renderEntity();
	SDL_RenderPresent(renderer);
}
/* ========================
*	Function: running()
*	accessor that returns the status if the program should continue to run
*/// ======================
bool Game::running()
{
	return isRunning;
}
/* ========================
*	Function: clean()
*	required function to destroy the window and render and to close all SDL background processes
*/// ======================
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Application subsystems destroyed..." << std::endl;
	std::cout << "Game cleaned..." << std::endl;
}