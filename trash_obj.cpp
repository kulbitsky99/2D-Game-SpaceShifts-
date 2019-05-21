#ifndef TRASH_METHODS_H
#define TRASH_METHODS_H

#include "trash.h"

sf::CircleShape & Trash::getCircle()
{
	return circle;
}

const int Trash::getCircleX()
{
	return circle.getPosition().x;
}

const int Trash::getCircleY()
{
	return circle.getPosition().y;
}

sf::Sprite & Trash::getSprite()
{
	return sprite;
}

Trash::Trash(int x, int y, float scale) :
	GameObject(x, y)
{
	circle = sf::CircleShape(1);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(x_null - TRASH_COLLIDE_RADIUS, y_null - TRASH_COLLIDE_RADIUS);

	//texture.loadFromFile("pictures/meteor.png");

	//sprite.setTexture	(texture);
	sprite.setPosition	(x_null - TRASH_COLLIDE_RADIUS, y_null - TRASH_COLLIDE_RADIUS);
	sprite.setScale		(scale, scale);
}

Trash::~Trash()
{
	//What should we do here?
}

#endif