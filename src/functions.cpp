#include "head.h"

void storeCreate(std::vector<Trash> & vector, sf::Texture & texture)
{
	for(int i = 0; i < STORE_SIZE / 4; i++) // MN
	{
		Trash trash_one(rand()%SCREEN_WIDTH, ZERO		  		 , TRASH_SCALE);
		Trash trash_two(rand()%SCREEN_WIDTH, SCREEN_HEIGHT 		 , TRASH_SCALE);

		Trash trash_three(ZERO,				 rand()%SCREEN_HEIGHT, TRASH_SCALE);
		Trash trash_four (SCREEN_WIDTH,		 rand()%SCREEN_HEIGHT, TRASH_SCALE);
		// fullfill it in a cycle
		vector.push_back(trash_one);
		vector.push_back(trash_two);
		vector.push_back(trash_three);
		vector.push_back(trash_four);

		for(int j = i; j < i + 4; j++) // MN
			vector[j].getSprite().setTexture(texture);
	}
}

void bullet_storeCreate (std::vector<Bullet> & bullet_vector, sf::Texture & texture)
{
	for(int i = 0; i < STORE_SIZE; i++)
	{
		Bullet bullet(0, 0, BULLET_SCALE);
		bullet.killObject();
		bullet.getSprite().setTexture(texture);
		bullet_vector.push_back(bullet);
	}
}