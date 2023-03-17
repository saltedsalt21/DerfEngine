#ifndef TEXTUREMANAGER_H_INCLUDED
#define TEXTUREMANAGER_H_INCLUDED

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* renderer)
	{
		SDL_Texture* TextureToReturn;
		SDL_Surface* tmpSurface = IMG_Load(filename);
		TextureToReturn = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);

		return TextureToReturn;
	}
};
#endif