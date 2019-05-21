#ifndef TRASH_H
#define TRASH_H

#include "game_obj.h"

#define TRASH_COLLIDE_RADIUS 	20   //emphirical value, may be changed!!!
#define TRASH_SCALE		0.25f  	

class Trash : public GameObject
{
	private :
		sf::CircleShape circle;
		sf::Texture 	texture;
		sf::Sprite 		sprite;

	public :

		Trash 	(int x, int y, float scale);
		~Trash 	();

		sf::CircleShape & 	getCircle 	();
		sf::Sprite 		&	getSprite	();
		
		const int 			getCircleX 	();
		const int 			getCircleY 	();
};

#endif
