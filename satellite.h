#ifndef SATELLITE_H
#define SATELLITE_H

#include "game_obj.h"

#define SPRITE_X	559
#define SPRITE_Y	243

#define SCALE	 	0.28f

#define SATELLITE_START_X 		670
#define SATELLITE_START_Y 		360
#define START_ORBIT				200.0
#define START_DELTA 			1.4
#define START_BETA 				0
#define DELAY 					10
#define EXTEND_JUMP 			150

#define DOUBLE_ANGLE(ARG)		(ARG) * 2

#define INCREASE_DELTA(ARG) 	(ARG) *= 1.01
#define DECREASE_DELTA(ARG) 	(ARG) /= 1.01

#define INCREASE_ORBIT(ARG) 	(ARG) *= 1.05
#define DECREASE_ORBIT(ARG) 	(ARG) /= 1.05

class Satellite : public GameObject
{
	private :
		sf::Texture 	texture;
		sf::Sprite 		sprite;
		float 			orbit;
		float 			delta;
		float 			beta;

	public :		

		 Satellite 			(int x, int y, float scale);
		~Satellite	       	();

		sf::Sprite 		& 	getSprite 	();

		const float 		showOrbit 	() const;
		float & 			getOrbit	();

		const float 		showDelta 	() const;
		float & 			getDelta	();

		const float 		showBeta 	() const;
		float & 			getBeta		();

};

#endif
