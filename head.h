#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <cstdio>

#include "objects.h"

#define SCREEN_WIDTH 			1340
#define SCREEN_HEIGHT 			720
#define ZERO					0

#define SPEED 					150

#define EARTH_RADIUS 			70
#define EARTH_X 				650
#define EARTH_Y 				350

#define STORE_SIZE 				256 //for trash
#define BULLET_STORE_SIZE 		64

#define SATELLITE_LIMIT			50

#define FAST_TIME(ARG) (ARG).asSeconds() * SPEED

int satelliteMove			(Satellite &, sf::Clock &);
int trashMove				(Trash &, sf::Time &, std::vector<int> &);
void bullet_alive			(std::vector<Bullet> &, sf::Vector2i &, Satellite &);
void bulletMove				(std::vector<Bullet> &, std::vector<Trash> &, /*Earth &,*/ std::vector<int> &);

void storeCreate			(std::vector<Trash> &, sf::Texture &);
void bullet_storeCreate 	(std::vector<Bullet> &, sf::Texture &);

#endif
