#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "SDL.h"
#include "SDL_image.h"
#include "GameObject.h"
#include "Map.h"
#include <iostream>

class Game
{
private:
	
	int tickCounter;
	bool isRunning;
	SDL_Renderer* renderer;
	SDL_Window* window;
	GameObject* player;
	Map* map;

public:

	Game()
	{
		tickCounter = 0;
		isRunning = NULL;
		window = NULL;
		renderer = NULL;
		player = NULL;
	}
	~Game()
	{
		std::cout << std::endl << "!!!GAME CLASS DELETED!!!" << std::endl;
		delete player;
		delete map;
	}

	void init(const char* title, int xposition, int yposition, int width, int height, bool fullscreen)
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
		
		player = new GameObject("assets/LittleGuy.png", renderer);
		map = new Map(renderer);

	}

	void handleEvents()
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
	}

	void update()
	{
		tickCounter++;
		std::cout << tickCounter << std::endl;

		player->Update();
	}

	void render()
	{
		SDL_RenderClear(renderer);
		//Add stuff here that is needed to be rendered
		map->DrawMap();
		player->Render();
		SDL_RenderPresent(renderer);
	}

	bool running()
	{
		return isRunning;
	}

	void clean()
	{
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		std::cout << "Application subsystems destroyed..." << std::endl;
		std::cout << "Game cleaned..." << std::endl;
	}
};
#endif