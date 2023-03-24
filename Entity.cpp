#include "Entity.h"
/*
* File: Entity.cpp
* Date: 3/24/23
*
* This is the cpp file for the Entity class. Defines function definitions for the Entity class
*/
Entity::Entity()
{
	xPosition = 0;
	yPosition = 0;

	entityCenterOffSetX = 16;
	entityCenterOffSetY = 16;

	velocityX = 0;
	velocityY = 0;
	acceleration = 0;
	deceleration = 0;

	maxVelocityX = 0;
	maxVelocityY = 0;

	texture = nullptr;
	TextureWidth = 0;
	TextureHight = 0;

	wKeyState = NULL;
	aKeyState = NULL;
	sKeyState = NULL;
	dKeyState = NULL;

}
Entity::~Entity()
{
	std::cout << "!!!GAME ENTITY DELETED!!!" << std::endl;
}
/* ========================
*	Function: Entity(...)
*	This constructor passes the entity class origin offsets for the origin, collisionBoxSize and acceleration and deceleration
*/// ======================
Entity::Entity(const char* textureName, int offsetPosx, int offsetPosy, int collisionBoxSizeX, int collisionBoxSizeY, double accel, double decel)
{
	entityCenterOffSetX = collisionBoxSizeX / 2;
	entityCenterOffSetY = collisionBoxSizeY / 2;

	xPosition = offsetPosx + entityCenterOffSetX;
	yPosition = offsetPosy + entityCenterOffSetY;

	velocityX = 0;
	velocityY = 0;
	acceleration = accel;
	deceleration = decel;

	maxVelocityX = 7.5;
	maxVelocityY = 7.5;

	texture = TextureManager::LoadTexture(textureName);
	TextureWidth = collisionBoxSizeX;
	TextureHight = collisionBoxSizeY;

	wKeyState = NULL;
	aKeyState = NULL;
	sKeyState = NULL;
	dKeyState = NULL;
}
/* ========================
*	Function: handleEntityEvents(DL_Event event)
*	Function to handle user input.
*	As of 3/24/23 the function updates the velocity of the player entity based on user input
*	User input moves the entity on screen using a momentum based movement system
*/// ======================
void Entity::handleEntityEvents(SDL_Event event)
{
	// see if any keys are down and increase velocity
	if (SDL_KEYDOWN == event.type)
	{	
		if (SDLK_w == event.key.keysym.sym)
		{
			std::cout << "Key W is down" << std::endl;
			wKeyState = true;
		}
		if (SDLK_a == event.key.keysym.sym)
		{
			std::cout << "Key a is down" << std::endl;
			aKeyState = true;
		}
		if (SDLK_s == event.key.keysym.sym)
		{
			std::cout << "Key s is down" << std::endl;
			sKeyState = true;
		}
		if (SDLK_d == event.key.keysym.sym)
		{
			std::cout << "Key d is down" << std::endl;
			dKeyState = true;
		}
	}
	if (SDL_KEYUP == event.type)
	{
		if (SDLK_w == event.key.keysym.sym)
		{
			std::cout << "Key W is up" << std::endl;
			wKeyState = false;
		}
		if (SDLK_a == event.key.keysym.sym)
		{
			std::cout << "Key a is up" << std::endl;
			aKeyState = false;
		}
		if (SDLK_s == event.key.keysym.sym)
		{
			std::cout << "Key s is up" << std::endl;
			sKeyState = false;
		}
		if (SDLK_d == event.key.keysym.sym)
		{
			std::cout << "Key d is up" << std::endl;
			dKeyState = false;
		}
	}
	// depending on what key is held down update the velocity
	if (wKeyState == true)
	{
		std::cout << "Key W is down" << std::endl;
		velocityY += -(acceleration);
		wKeyState = true;
	}
	if (aKeyState == true)
	{
		std::cout << "Key a is down" << std::endl;
		velocityX += -(acceleration);
		aKeyState = true;
	}
	if (sKeyState == true)
	{
		std::cout << "Key s is down" << std::endl;
		velocityY += acceleration;
		sKeyState = true;
	}
	if (dKeyState == true)
	{
		std::cout << "Key d is down" << std::endl;
		velocityX += acceleration;
		dKeyState = true;
	}
	// check to see if the entity should slow down in the x and y axis
	if ((aKeyState == false) && (dKeyState == false))
	{
		if (velocityX > 0)
		{
			velocityX -= deceleration;
			if (velocityX < 0)
			{
				velocityX = 0;
			}
		}
		else if (velocityX < 0)
		{
			velocityX += deceleration;
			if (velocityX > 0)
			{
				velocityX = 0;
			}
		}
	}
	if ((wKeyState == false) && (sKeyState == false))
	{
		if (velocityY > 0)
		{
			velocityY -= deceleration;
			if (velocityY < 0)
			{
				velocityY = 0;
			}
		}
		else if (velocityY < 0)
		{
			velocityY += deceleration;
			if (velocityY > 0)
			{
				velocityY = 0;
			}
		}
	}

	// ensure x velocity is not over extended
	if (velocityX > maxVelocityX)
	{
		velocityX = maxVelocityX;
	}
	else if (velocityX < -(maxVelocityX))
	{
		velocityX = -maxVelocityX;
	}
	// ensure y velocity is not over extended
	if (velocityY > maxVelocityY)
	{
		velocityY = maxVelocityY;
	}
	else if (velocityY < -(maxVelocityY))
	{
		velocityY = -maxVelocityY;
	}

}
/* ========================
*	Function: entityUpdate()
*	updates the position of the entity based on velocity
*/// ======================
void Entity::entityUpdate()
{
	xPosition += velocityX;
	yPosition += velocityY;
}
/* ========================
*	Function: renderEntity()
*	sends a texture to be rendered to the TextureManager
*/// ======================
void Entity::renderEntity()
{
	SDL_Rect destRect;

	destRect.x = xPosition - entityCenterOffSetX;  //the x coordinate
	destRect.y = yPosition - entityCenterOffSetY; // the y coordinate
	destRect.w = TextureWidth * 2; //the width of the texture multiplied by two to increase visual size
	destRect.h = TextureHight * 2; //the hight of the texture

	TextureManager::DrawTextureWithBounds(texture, destRect);
}

void Entity::collisionSetBack()
{

}