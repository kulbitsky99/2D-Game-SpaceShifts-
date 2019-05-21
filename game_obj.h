#ifndef GAME_OBJ_H
#define GAME_OBJ_H

#include <iostream>
#include <SFML/Graphics.hpp>

#define ALIVE 			1
#define DEAD  			0
#define START_VELOCITY 	10

class GameObject
{
	protected :

		int 	x_null;
		int 	y_null;
		int 	is_alive;

	public :

		GameObject	(int x, int y);
		~GameObject	();

		const int 	getX_Null();
		const int 	getY_Null();

		const int 	isAlive();
		void 		killObject();
		void 		aliveObject();
};

#endif
