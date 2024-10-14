#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Math.h"
#include "Constants.h"
#include "Apple.h"
#include "Lemon.h"
#include "SoundMenager.h"
namespace AppleGame
{
	struct PlayerUi
	{
		sf::Texture PlayerTexture;
	};
	enum class PlayerDirection
	{
		Right = 0,
		Up,
		left,
		Down

	};
	struct PlayerStatistic
	{
		int Score = 0;
		int speed = 0;
	};
	struct Player
	{
		pos2d position;
		sf::Sprite sprite;
		PlayerDirection direction;
		PlayerStatistic statistic;
	};

	struct PlayerData
	{
		Player Player;


	};
	enum GameMode;

	void PlayerInit(Player& player); 
    void RestartPlayer(Player& player);
    void PlayerMovement(Player& player, float deltaTime);
    void CheckForApples(PlayerData& data, AppleData& apple, Sounds& sound, const GameMode& mode);
	bool CheckForLemonz(Player& player, LemonData& lemonz);
    bool CheckBorders(Player& player);
	void DrawPlayer(Player& player, sf::RenderWindow& window);
}