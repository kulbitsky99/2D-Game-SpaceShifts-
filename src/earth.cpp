#include "earth.h"

Earth::Earth(int x, int y, float scale):
	GameObject(x, y)
{
	earth_texture.loadFromFile("pictures/earth.png");

	earth.setTexture	(earth_texture);
	earth.setPosition	(sf::Vector2f(x_null, y_null));
	earth.setScale		(scale, scale);
}

Earth::~Earth()
{
	// ???
}

const sf::Sprite & Earth::getSprite() const
{
	return earth;
}