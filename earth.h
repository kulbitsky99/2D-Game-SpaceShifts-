#ifndef EARTH_H
#define EARTH_H

#include "game_obj.h"

#define EARTH_SPRITE_X			570
#define EARTH_SPRITE_Y			240

#define EARTH_SCALE	 			0.22f  

class Earth : protected GameObject
{
	private :

		sf::Texture earth_texture;
		sf::Sprite 	earth;

	public :
	
		Earth 	(int x, int y, float scale);
		~Earth 	();

		const sf::Sprite & getSprite() const; 
};

#endif