#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <optional> 

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 204,204 }), "SFML works!");

	sf::Texture PIVO;
	if (!PIVO.loadFromFile(std::string(ASSETS_PATH) + "Pivo.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite PIVO_sprite(PIVO);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>()) { window.close(); }
		}

		window.clear();
		window.draw(PIVO_sprite);
		window.display();
	}
}