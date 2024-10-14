#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Math.h"


namespace AppleGame
{

	struct LemonUi
	{
		sf::Texture lemon;
	};
	struct Lemon
	{
		pos2d position;
		sf::Sprite sprite;
	};
	struct LemonData
	{
		int LemonzNum;
		Lemon* lemon;
		LemonData()
		{
			LemonzNum = LemonzNum = (int)(MinimumLemonzNum + rand() / (float)(RAND_MAX) * (MaximumLemonzNum - MinimumLemonzNum));
			lemon = new Lemon[LemonzNum];
		}
		~LemonData()
		{
			delete[] lemon;
		}
	};

	void ReselectLemonNum(LemonData& data);
	void LemonzInit(LemonData& data);
	void lemonzrestart(LemonData& data);
	void DrawLemonz(LemonData& data, sf::RenderWindow& window);
}