#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED
#include "TextureManager.cpp"

class GameObject 
{
private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;

public:
	GameObject(){}

	~GameObject()
	{
		std::cout << std::endl << "!!!OBJECT DELETED!!!" << std::endl;
	}

	GameObject(const char* texturesheet, SDL_Renderer* rend)
	{
		renderer = rend;
		objTexture = TextureManager::LoadTexture(texturesheet, rend);
	}

	void Update()
	{
		xpos = 0;
		ypos = 0;

		srcRect.h = 64;
		srcRect.w = 64;
		srcRect.x = 0;
		srcRect.y = 0;

		destRect.h = srcRect.h * 2;
		destRect.w = srcRect.w * 2;
		destRect.x = xpos;
		destRect.y = ypos;
	}

	void Render()
	{
		SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
	}
};
#endif