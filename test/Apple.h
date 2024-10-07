#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Math.h"

namespace AppleGame
{
	struct AppleUI
	{
		sf::Texture StandartAppleTexTure;
	};
	struct StandartApple
	{
		pos2d position = { 0.f,0.f };
		sf::Sprite sprite;

	};
	struct AppleData
	{
		int StandartApplesNum;
		StandartApple* Standart;
		AppleData()
		{
			StandartApplesNum = (int)(MinimumAppleNum + rand() / (float)(RAND_MAX) * (MaximumAppleNum - MinimumAppleNum));
			Standart = new StandartApple[StandartApplesNum];
		}
		~AppleData()
		{
			delete[] Standart;
		}
	};

	void ReselectAppleNum(AppleData& apple);
	void AppleInit(AppleData& apple);
	void AppleRespawn(StandartApple& apple);
	void AppleRestart(AppleData& apple);
	void DrawApples(AppleData& apple, sf::RenderWindow& window);

}