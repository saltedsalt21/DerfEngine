#include "TextureManager.h"

static SDL_Renderer* Renderer;

void TextureManager::setRenderer(SDL_Renderer* rend)
{
	Renderer = rend;
}

SDL_Texture* TextureManager::LoadTexture(const char* filename)
{
	SDL_Texture* TextureToReturn;
	SDL_Surface* tmpSurface = IMG_Load(filename);
	TextureToReturn = SDL_CreateTextureFromSurface(Renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return TextureToReturn;
}

void TextureManager::DrawTexture(SDL_Texture* texture)
{
	SDL_RenderCopy(Renderer, texture, NULL, NULL);
}

void TextureManager::DrawTextureWithBounds(SDL_Texture* texture, SDL_Rect drawRect)
{
	SDL_RenderCopy(Renderer, texture, NULL, &drawRect);
}