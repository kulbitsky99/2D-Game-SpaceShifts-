#include "head.h"


/*
lots of PHP style
avoid this by using simple functions to complete regular actions
like switch
cycle

*/

/*


int main()
{
	GameEngine::EngineManager e_manager;
	
}

*/



int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Work mf");

	sf::Clock clock;
	sf::Clock clock_sat;
	sf::Clock clock_bullet;

	sf::Time time;

	sf::Event main_event;

	sf::Vector2i mousePosition;

	//temporary volatile
	int alive_numb = 0;

	sf::Texture trash_texture;
	trash_texture.loadFromFile("pictures/meteor.png");
	sf::Texture bullet_texture;
	bullet_texture.loadFromFile("pictures/bullet.png");

	//creating vector of trash
	std::vector<Trash> trash_vector;
	storeCreate(trash_vector, trash_texture);

	//creating vector of bullets
	std::vector<Bullet> bullet_vector;
	bullet_storeCreate(bullet_vector, bullet_texture);

	//Satellite creating
	Satellite satellite(SATELLITE_START_X, SATELLITE_START_Y, SCALE);
	sf::Vector2u spriteSize = satellite.getSprite().getTexture() -> getSize();
	satellite.getSprite().setOrigin(spriteSize.x / 2, spriteSize.y / 2);

	//Earth creating
	Earth earth(EARTH_SPRITE_X, EARTH_SPRITE_Y, EARTH_SCALE);

	//Background
	sf::Texture background_texture;
	sf::Sprite 	background;
	background_texture.loadFromFile("pictures/background.png");
  	
  	sf::Vector2u texture_size = background_texture.getSize(); //Get size of texture.
    sf::Vector2u window_size  = window.getSize();             //Get size of window.

    float scale_x = (float)window_size.x / texture_size.x;	  //Calculate scale.
    float scale_y = (float)window_size.y / texture_size.y;    //Calculate scale.

    background.setTexture(background_texture);
    background.setScale	 (scale_x, scale_y);

    //Font
    sf::Font font;
    font.loadFromFile("CyrilicOld.TTF");
    sf::Text score("", font, 24), bullet_left("", font, 24);
    score.setFillColor(sf::Color::White);
    score.setStyle(sf::Text::Bold);
    score.setString("SCORE: ");
    score.setPosition(10, 10);

    bullet_left.setFillColor(sf::Color::White);
    bullet_left.setStyle(sf::Text::Bold);
    bullet_left.setString("BULLETS LEFT: ");
    bullet_left.setPosition(10, 40);

    std::vector<int> playerScore;
	playerScore.push_back(0);
	playerScore.push_back(BULLET_STORE_SIZE);
	//std::cout << playerScore[0] << " " << playerScore[1] << "\n";
    

	while(window.isOpen())
	{

		time = clock.getElapsedTime();

		//satellite rotation
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		sf::Vector2f center = satellite.getSprite().getPosition();
		sf::Vector2f direction = sf::Vector2f(mousePosition.x, mousePosition.y) - center;
		const float Pi = 3.14159f;
		satellite.getSprite().setRotation(20 + atan2f(direction.y, direction.x) * 180 / Pi);

		while(window.pollEvent(main_event))
			switch(main_event.type)
			{
				case sf::Event::Closed :
					window.close();
					break;

				case sf::Event::KeyPressed :
				{
					if(main_event.key.code == sf::Keyboard::Up)
					{
						INCREASE_DELTA(satellite.getDelta());
						INCREASE_ORBIT(satellite.getOrbit());
					}

					if(main_event.key.code == sf::Keyboard::Down)
					{
						if(satellite.getOrbit() > SATELLITE_LIMIT)
						{
							DECREASE_DELTA(satellite.getDelta());
							DECREASE_ORBIT(satellite.getOrbit());
						}
					}

					break;
				}
				case sf::Event::MouseButtonPressed:
				{
					if(main_event.mouseButton.button == sf::Mouse::Left)
					{
				 		mousePosition = sf::Mouse::getPosition(window);
				 		bullet_alive(bullet_vector, mousePosition, satellite);
					}
					break;
				}
				default:
				{
					break;
				}
			}

		trashMove(trash_vector[alive_numb], time, playerScore);
		satelliteMove(satellite, clock_sat);
		bulletMove(bullet_vector, trash_vector,/* earth,*/ playerScore);
		//std::cout << playerScore[0] << " " << playerScore[1] << "\n";

		window.clear(sf::Color::White);
		window.draw(background);
		
		if(trash_vector[alive_numb].isAlive())
			window.draw(trash_vector[alive_numb].getSprite());
		else
		{
			alive_numb = (alive_numb + 1) % STORE_SIZE;//move to the beginning
			clock.restart();
		}

		window.draw(satellite.getSprite());
		window.draw(earth.getSprite());
		playerScore[1] = BULLET_STORE_SIZE;
		for(int i = 0; i < BULLET_STORE_SIZE; i++)
		{
			if(bullet_vector[i].isAlive() == ALIVE)
			{
				window.draw(bullet_vector[i].getSprite());
				playerScore[1]--;
			}
		}

		std::ostringstream playerScoreString, bulletLeftString;
		playerScoreString << 	playerScore[0];
		bulletLeftString << 	playerScore[1];
		score.setString("SCORE: " + playerScoreString.str());
		bullet_left.setString("BULLETS LEFT: " + bulletLeftString.str());
		window.draw(score);
		window.draw(bullet_left);

		window.display();
	}
	return 0;

}

