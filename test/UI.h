#pragma once
#include "SFML/Graphics.hpp"
#include "Math.h"
#include "Constants.h"
namespace AppleGame
{

		struct LoseScreen
		{
			sf::RectangleShape back;
			sf::Text LuseLabel;
			sf::Text ScoreStatistic;
			sf::Text TimeStatistic;
			sf::Text InstructionLabel;
			sf::Text PlayerSpeed;
		};
		struct GameUi
		{
			sf::Text ScoreLable;
			sf::Text PlayerSpeedLable;
		};
		struct Recurces;
		struct Dataes;
		void LoseScreenInit(LoseScreen& lose, sf::Font& font, const int score, const float speed, Time Play);
		void DrawLoseScreen(sf::RenderWindow& window, LoseScreen& lose);
		void UiInit(GameUi& ui, sf::Font& font);
		void DrawGame(sf::RenderWindow& window, Recurces& recurces, Dataes& data);
}