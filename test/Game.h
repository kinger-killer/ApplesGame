#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "constants.h"
#include "Apple.h"
#include "Lemon.h"
#include "Player.h"
#include "iostream"
#include "UI.h"

namespace AppleGame
{
			struct Fonts
			{
				sf::Font font;
			};
			struct Textes
			{
				sf::Text score;
				sf::Text speed;
				sf::Text GameOver;
			};
			struct Sounds
			{
				sf::Sound eat;
				sf::Sound death;
			};
			struct SoundBuffers 
			{
				sf::SoundBuffer eat;
				sf::SoundBuffer death;
			};
		struct Recurces
		{
			PlayerUi player;
			AppleUI apple;
			LemonUi lemon;

			LoseScreen lose;

			
			Fonts font;
			
			Sounds sounds;
			SoundBuffers buffers;

			Textes texts;
		};
		struct GameStatus
		{
			bool IsGameOver = false;
		};
		struct Statistics
		{
			//std::sring PlayerName;
			float PlayTimeAsSeconds = 0;
			Time playTime;
		};
		struct Dataes
		{
			AppleData apple;
			PlayerData player;
			LemonData lemon;
		};
		enum GameMode
		{
			standart,
			withoutAppleRespawn,
			withoutAcceleration,
			immortal
		};
		struct Input
		{
			PlayerDirection direction = PlayerDirection::Right;
		};
	struct GameState
	{
		Input input;
		Recurces ui;
		GameMode mode;		
		GameStatus status;
		Statistics statistic;
		Dataes data;
	};

	bool DoesTexturesLoaded(Recurces& ui);
	bool DoesSoundsLoaded(SoundBuffers& buffer);
	bool DoesFontsLoaded(Fonts& fonts);
	void GameInit(GameState& game);
	void GameRestart(Player& player,AppleData& apple, LemonData& lemon);
	PlayerDirection GameImputReading(PlayerDirection& current);
	void GameLose(sf::RenderWindow& window, sf::Font& font, sf::Sound& sound, const int score, const int speed, const Time time);
	void UpdateGameUi(Textes& texts, PlayerStatistic& statistic);
	void BorderPortal(PlayerData& player);
	void GameUpdate(sf::Clock& clock, GameState& game, float DeltaTime);
}