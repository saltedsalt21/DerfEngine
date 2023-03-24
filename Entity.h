#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include <iostream>
/*
* File: Entity.h
* Date: 3/24/23
*
* Header file to set up the Entity class.
*/
class Entity
{
private:
	// position of the center of the collision box
	int xPosition;
	int yPosition;

	// offsets for the center of the entity collision box
	// These will be used to get to the TOP-LEFT corner of the bounding box for rendering
	// REMEMBER SDL USES A LEFT->RIGHT X-AXIS BUT FOR Y-AXIS IT IS FROM ORIGIN->DOWN (y-xis is inverse logic)
	int entityCenterOffSetX;
	int entityCenterOffSetY;

	// movement variables
	double velocityX;
	double velocityY;
	double acceleration;
	double deceleration;
	
	double maxVelocityX;
	double maxVelocityY;

	// Display related variables
	SDL_Texture* texture;
	int TextureWidth;
	int TextureHight;

	bool wKeyState;
	bool aKeyState;
	bool sKeyState;
	bool dKeyState;

public:

	Entity();
	~Entity();

	//constructor gets the texture, initial xposition and yposition, texture dimensions, acceleration and deceleration 
	Entity(const char* textureName, int offsetPosx, int offsetPosy, int collisionBoxSizeX, int collisionBoxSizeY, double accel, double decel);

	void handleEntityEvents(SDL_Event event);
	void renderEntity();
	void entityUpdate();

	void collisionSetBack();
};
#endif