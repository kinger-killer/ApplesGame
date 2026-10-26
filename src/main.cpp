#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <optional> 

#include "player.hpp"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main()
{
	sf::Texture playerTexture;
	if(!playerTexture.loadFromFile(std::string(ASSETS_PATH) + "Textures/Player.png"))
	{ return EXIT_FAILURE; }

	player myPlayer(playerTexture, { SCREEN_WIDTH /2,SCREEN_HEIGHT /2},100.0f);

	sf::RenderWindow window(sf::VideoMode({ SCREEN_WIDTH,SCREEN_HEIGHT }), "SFML works!");
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
		myPlayer.Render(window);
		window.display();

		myPlayer.Update(deltaTime);
	}

	return 0;
}