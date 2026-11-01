#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <optional> 

#include "player.hpp"
#include "appleManager.hpp"

const float SCREEN_WIDTH = 800.0f;
const float SCREEN_HEIGHT = 600.0f;



int main()
{
	sf::Texture playerTexture;
	if(!playerTexture.loadFromFile(std::string(ASSETS_PATH) + "Textures/Player.png"))
	{ return EXIT_FAILURE; }

	Player myPlayer({ SCREEN_WIDTH /2,SCREEN_HEIGHT /2},100.0f);

	AppleManager apples({ SCREEN_WIDTH,SCREEN_HEIGHT }, 20);

	sf::RenderWindow window(sf::VideoMode({ static_cast<unsigned>(SCREEN_WIDTH), static_cast<unsigned>(SCREEN_HEIGHT) }), "SFML works!");
	window.setFramerateLimit(60);

	sf::Clock gameClock;
	gameClock.start();
	
	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>()) { window.close(); }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{ window.close();}
		}
		float deltaTime = gameClock.restart().asSeconds();

		window.clear();
		apples.Render(window);
		myPlayer.Render(window);
		window.display();

		myPlayer.Update(deltaTime);
		apples.checkCollision(myPlayer);
	}

	return 0;
}
