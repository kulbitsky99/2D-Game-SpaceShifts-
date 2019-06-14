#include "head.h"



// typedef PE PhysicalEngine
// PE::satelliteMove(...);

int satelliteMove(Satellite & satellite, sf::Clock & clock)
{
	if(clock.getElapsedTime().asMilliseconds() > DELAY)
	{
		float angle = asin(satellite.showDelta() / satellite.showOrbit());
		
		float jump = EXTEND_JUMP * satellite.showDelta() * cos(angle);

		float delta_x = - jump * sin(angle + satellite.showBeta());
		float delta_y = - jump * cos(angle + satellite.showBeta());

		satellite.getBeta() += DOUBLE_ANGLE(angle);

		satellite.getSprite().setPosition(satellite.getX_Null() + delta_x,
										  satellite.getY_Null() + delta_y);

		clock.restart();
	}

	return 0;
}

int trashMove(Trash & trash, sf::Time & time, std::vector<int> & playerScore)
{
	if(abs(trash.getSprite().getPosition().x + TRASH_COLLIDE_RADIUS - EARTH_X) < EARTH_RADIUS &&
	   abs(trash.getSprite().getPosition().y + TRASH_COLLIDE_RADIUS - EARTH_Y) < EARTH_RADIUS)
	{
		trash.killObject();
		playerScore[0] -= 5;
		return 0;
	}

	int delta_x = EARTH_X - trash.getX_Null();
	int delta_y = EARTH_Y - trash.getY_Null();

	float radius = sqrt(delta_x * delta_x + delta_y * delta_y);

	trash.getCircle().setPosition(trash.getX_Null() + (delta_x / radius) * FAST_TIME(time),
								  trash.getY_Null() + (delta_y / radius) * FAST_TIME(time));

	trash.getSprite().setPosition(trash.getX_Null() + (delta_x / radius) * FAST_TIME(time),
								  trash.getY_Null() + (delta_y / radius) * FAST_TIME(time));

	return 0;
}

void bullet_alive (std::vector<Bullet> & bullet_vector, sf::Vector2i & mousePosition, 
				  Satellite & satellite)
{
	sf::Vector2f sat_coord(satellite.getSprite().getPosition().x, satellite.getSprite().getPosition().y);
	float velocity = 0.f;
	float way = 0.f;
	for(int i = 0; i < BULLET_STORE_SIZE; i++)
	{
		if(bullet_vector[i].isAlive() == DEAD)
		{
			bullet_vector[i].aliveObject();
			way = sqrt((mousePosition.x - sat_coord.x) * (mousePosition.x - sat_coord.x) + 
							 (mousePosition.y - sat_coord.y) * (mousePosition.y - sat_coord.y));
			velocity = (mousePosition.x - sat_coord.x) / way;
			bullet_vector[i].setVX(velocity);
			velocity = (mousePosition.y - sat_coord.y) / way;
			bullet_vector[i].setVY(velocity);
			bullet_vector[i].getSprite().setPosition(sat_coord.x - BULLET_COLLIDE_RADIUS,
													 sat_coord.y - BULLET_COLLIDE_RADIUS);
			break;
		}
	}
}

void bulletMove (std::vector<Bullet> & bullet_vector, std::vector<Trash> & trash_vector,/* Earth & earth*/ std::vector<int> & playerScore)
{

	for(int i = 0; i < BULLET_STORE_SIZE; i++)
	{
		if(bullet_vector[i].isAlive() == ALIVE)
		{
			sf::Vector2f bullet_coord	(bullet_vector[i].getSprite().getPosition().x, 
										 bullet_vector[i].getSprite().getPosition().y);
			bullet_coord.x += bullet_vector[i].getVX() * TIME;
			bullet_coord.y += bullet_vector[i].getVY() * TIME;

			//screen_exit
			bullet_vector[i].getSprite().setPosition(bullet_coord.x, bullet_coord.y);
			if(bullet_coord.x >= SCREEN_WIDTH  || bullet_coord.x <= SCREEN_EXIT ||
			   bullet_coord.y >= SCREEN_HEIGHT || bullet_coord.y <= SCREEN_EXIT)
			{
				bullet_vector[i].killObject();
			}
		}

		//collide bullet with trash
		for(int i = 0; i < BULLET_STORE_SIZE; i++)
			for(int j = 0; j < STORE_SIZE; j++)
			{
				if((bullet_vector[i].isAlive() == ALIVE) && (trash_vector[j].isAlive() == ALIVE))
				{
					float distance;
					sf::Vector2f bullet_coord	(bullet_vector[i].getSprite().getPosition().x, 
										 		 bullet_vector[i].getSprite().getPosition().y);
					sf::Vector2f trash_coord	(trash_vector[j].getSprite().getPosition().x, 
										 		 trash_vector[j].getSprite().getPosition().y);

					distance = sqrt((bullet_coord.x - trash_coord.x) * (bullet_coord.x - trash_coord.x) + 
									(bullet_coord.y - trash_coord.y) * (bullet_coord.y - trash_coord.y));
					if(	(distance <= (BULLET_COLLIDE_RADIUS + TRASH_COLLIDE_RADIUS) / 2) &&
						(bullet_coord.x <= SCREEN_WIDTH + SCREEN_EXIT  && bullet_coord.x >= 0 &&
			   			 bullet_coord.y <= SCREEN_HEIGHT + SCREEN_EXIT && bullet_coord.y >= 0)) 
			   		{
						bullet_vector[i].killObject();
						trash_vector[j].killObject();
						playerScore[0]++;
						//std::cout << "I died \n";
					}
				}
			}

		//collide bullet with earth
		for(int i = 0; i < BULLET_STORE_SIZE; i++)
			{
				if(bullet_vector[i].isAlive() == ALIVE)
				{
					float distance;
					sf::Vector2f bullet_coord	(bullet_vector[i].getSprite().getPosition().x, 
										 		 bullet_vector[i].getSprite().getPosition().y);
					sf::Vector2f earth_coord	(EARTH_X, 
										 		 EARTH_Y);

					distance = sqrt((bullet_coord.x - earth_coord.x) * (bullet_coord.x - earth_coord.x) + 
									(bullet_coord.y + BULLET_COLLIDE_RADIUS - earth_coord.y) * (bullet_coord.y + BULLET_COLLIDE_RADIUS - earth_coord.y));
					if(distance <= (BULLET_COLLIDE_RADIUS + EARTH_RADIUS) / 1.1) //just podgon :)
					{
						bullet_vector[i].killObject();
						playerScore[0]--;
					}
				}
			}			

	}
}

