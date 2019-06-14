#ifndef SATELLITE_METHODS_H
#define SATELLITE_METHODS_H

#include "satellite.h"
#include "game_obj.h"

Satellite::Satellite(int x, int y, float scale) :
	GameObject	(x, y),
	orbit 		(START_ORBIT),
	delta 		(START_DELTA),
	beta 		(START_BETA)

{
	texture.loadFromFile("pictures/tesla.png");

	sprite.setTexture	(texture);
	sprite.setPosition	(x_null, y_null);
	sprite.setScale		(scale, scale);
}

sf::Sprite 	& Satellite::getSprite()
{
	return sprite;
}

float Satellite::showOrbit()
{
	return orbit;
}

float & Satellite::getOrbit()
{
	return orbit;
}

float Satellite::showDelta() const
{
	return 	delta;
}

float & Satellite::getDelta()
{
	return delta;
}

float Satellite::showBeta()
{
	return 	beta;
}

float & Satellite::getBeta()
{
	return beta;
}

Satellite::~Satellite()
{
	//What should we do here?
}

#endif