#include <assert.h>
#include "AssetsManager.hpp"

AssetsManager::AssetsManager()
{
	assert(addFont("main", std::string(ASSETS_PATH) + "Fonts/MainFont.otf") && "Main Font Load Failed");

	assert(addTexture("apple", std::string(ASSETS_PATH) + "Textures/Apple.png") && "Apple Texture Load Failed");
	assert(addTexture("player", std::string(ASSETS_PATH) + "Textures/Player.png") && "Player Texture Load Failed");
	assert(addTexture("rock", std::string(ASSETS_PATH) + "Textures/Rock.png") && "Rock Texture Load Failed");

	assert(addSound("eat", std::string(ASSETS_PATH) + "Audio/AppleEat.wav") && "AppleEat Sound Load Failed");
	assert(addSound("death", std::string(ASSETS_PATH) + "Audio/Death.wav") && "Death Sound Load Failed");
}


