#ifndef TEXTUREMANAGER_H_INCLUDED
#define TEXTUREMANAGER_H_INCLUDED

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class TextureManager
{
public:
	static void setRenderer(SDL_Renderer* rend);

	static SDL_Texture* LoadTexture(const char* filename);

	static void DrawTexture(SDL_Texture* texture);
	static void DrawTextureWithBounds(SDL_Texture* texture, SDL_Rect drawRect);
};
#endif