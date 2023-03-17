#pragma once
#include "TextureManager.cpp"

class Map
{
private:

	// map is width of screen by hight of screen
	int TileLayout[25][20];
	SDL_Rect srcR, destR;

	SDL_Texture* Wall;
	SDL_Texture* Barrier;

	SDL_Renderer* renderer;

public:

	Map(SDL_Renderer* rend)
	{
		renderer = rend; 
		Wall = TextureManager::LoadTexture("assets/wall.png", renderer);
		Barrier = TextureManager::LoadTexture("assets/test.png", renderer);

		srcR.x = 0;
		srcR.y = 0;
		srcR.w = 32;
		srcR.h = 32;

		destR.x = 0;
		destR.y = 0;
		destR.w = 32;
		destR.h = 32;


		for (int i = 0; i < 25; i++)
		{
			for (int q = 0; q < 20; q++)
			{
				TileLayout[i][q] = 0;
			}
		}

		for (int i = 0; i < 25; i++)
		{
			TileLayout[i][0] = 1;
			TileLayout[i][19] = 1;
		}
		for (int i = 0; i < 20; i++)
		{
			TileLayout[0][i] = 1;
			TileLayout[24][i] = 1;
		}

	}

	void LoadMap()
	{

	}

	void DrawMap()
	{
		for (int i = 0; i < 25; i++)
		{
			for (int q = 0; q < 20; q++)
			{
				destR.x = (i * 32);
				destR.y = (q * 32);

				switch (TileLayout[i][q])
				{
				case 0: SDL_RenderCopy(renderer, Wall, &srcR, &destR); break;
				case 1: SDL_RenderCopy(renderer, Barrier, &srcR, &destR); break;
				default:
					break;
				}
			}
		}
	}
};