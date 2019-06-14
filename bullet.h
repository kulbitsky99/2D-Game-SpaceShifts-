#ifndef BULLET_H
#define BULLET_H

#include "game_obj.h"

#define TIME 					5
#define SCREEN_EXIT 			-50

#define BULLET_COLLIDE_RADIUS 	30	//emphirical value, may be changed!!!
#define BULLET_SCALE 			0.05f


class Bullet : public GameObject
{
	private :

		sf::Sprite sprite;
		sf::Texture texture;

		// you may use sf::Vector2f to store the velocity data
		float velocity_x_;
		float velocity_y_;
		
	public :

		sf::Sprite & 		getSprite ();

		float getVX();
		float getVY();
		void 		setVX(float velocity_x);
		void		setVY(float velocity_y);
		Bullet 	(int x, int y, float scale);
		~Bullet 	();
};

#endif