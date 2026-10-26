#pragma once 

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <memory>


class AssetsManager
{
public:
	static AssetsManager& getInstance() 
	{
		static AssetsManager obj;
		return obj;
	}

	

private:
	AssetsManager() {}

	std::vector<std::unique_ptr<sf::Texture>> Textures;
	std::vector<std::unique_ptr<sf::Font>> Fonts;
	std::vector<std::unique_ptr<sf::SoundBuffer>> SoundBuffers;
};