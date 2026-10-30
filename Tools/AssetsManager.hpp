#pragma once 

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <unordered_map>
#include <string>

class AssetsManager
{
public:
	static AssetsManager& getInstance() 
	{
		static AssetsManager obj;
		return obj;
	}

	sf::SoundBuffer* getSound(std::string name)
	{
		auto it = Audio.find(name);
		return it != Audio.end() ? &it->second : nullptr;
	}

	sf::Texture* getTexture(std::string name)
	{
		auto it = Textures.find(name);
		return it != Textures.end() ? &it->second : nullptr;
	}

	sf::Font* getFont(std::string name)
	{
		auto it = Fonts.find(name);
		return it != Fonts.end() ? &it->second : nullptr;
	}

	bool addTexture(std::string name,std::string path)
	{
		if (name.empty() || path.empty())
			return false;

		sf::Texture newTexture;
		if (!newTexture.loadFromFile(path))
			return false;

		Textures.insert({name,newTexture});
		return true;
	}
	
	bool addFont(std::string name, std::string path)
	{
		if (name.empty() || path.empty())
			return false;

		sf::Font newFont;
		if (!newFont.openFromFile(path))
			return false;

		Fonts.insert({ name,newFont });
		return true;
	}

	bool addSound(std::string name, std::string path)
	{
		if (name.empty() || path.empty())
			return false;

		sf::SoundBuffer newSound;
		if (!newSound.loadFromFile(path))
			return false;

		Audio.insert({ name,newSound });
		return true;
	}

private:
	AssetsManager();

	std::unordered_map<std::string, sf::Texture> Textures;
	std::unordered_map < std::string, sf::Font> Fonts;
	std::unordered_map < std::string, sf::SoundBuffer> Audio;
};