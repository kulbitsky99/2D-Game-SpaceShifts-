#ifndef BULLET_METHODS_H
#define BULLET_METHODS_H

#include "bullet.h"
#include "game_obj.h"

sf::Sprite & Bullet::getSprite ()
{
	return sprite;
}

float Bullet::getVX()
{
	return velocity_x_;
}
float Bullet::getVY()
{
	return velocity_y_;
}
void 		Bullet::setVX(float velocity_x)
{
	velocity_x_ = velocity_x;
}
void		Bullet::setVY(float velocity_y)
{
	velocity_y_ = velocity_y;
}

Bullet::Bullet(int x, int y, float scale) :
	GameObject(x, y)
{
	
	/*texture.loadFromFile("pictures/meteor.png");
	sprite.setTexture	(texture);*/

	sprite.setPosition	(x, y);
	sprite.setScale		(scale / 1.5, scale);
}

Bullet::~Bullet()
{
	//What should we do here?
}

#endif