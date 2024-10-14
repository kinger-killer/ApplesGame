#include "Apple.h"

namespace AppleGame
{

	void ReselectAppleNum(AppleData& apple)
	{
		delete[] apple.Standart;
		apple.StandartApplesNum = (int)(MinimumAppleNum + rand() / (float)(RAND_MAX) * (MaximumAppleNum - MinimumAppleNum));
		apple.Standart = new StandartApple[apple.StandartApplesNum];
	}
	void DrawApples(AppleData& apple, sf::RenderWindow& window)
	{
		for (int i = 0; i < apple.StandartApplesNum; ++i)
		{
			DrawSpraite(window, apple.Standart[i].sprite);
		}
	}
	void AppleInit(AppleData& apple)
	{
		ReselectAppleNum(apple);
		for (int i = 0; i < apple.StandartApplesNum; ++i)
		{
			SetSpriteSize(apple.Standart[i].sprite, AppleSize, AppleSize);
			SetSpriteRelativeOrigen(apple.Standart[i].sprite, {0.5f,0.5f});
			apple.Standart[i].position.x = (2.5 * PlayerSize) + rand() / (float)RAND_MAX * ((ScreenWidth - (2.5f * PlayerSize)) - (2.5 * PlayerSize));
			apple.Standart[i].position.y = (2.5 * PlayerSize) + rand() / (float)RAND_MAX * ((ScreenHeight - (2.5f * PlayerSize)) - (2.5 * PlayerSize));
			apple.Standart[i].sprite.setPosition(apple.Standart[i].position.x, apple.Standart[i].position.y);
			std::cout << std::to_string(apple.Standart[i].position.x) << "," << std::to_string(apple.Standart[i].position.y) << std::endl;
		}
	}

	void AppleRespawn(StandartApple& apple) 
	{

			apple.position.x = (2.5 * PlayerSize) + rand() / (float)RAND_MAX * ((ScreenWidth - (2.5f * PlayerSize)) - (2.5 * PlayerSize));
			apple.position.y = (2.5 * PlayerSize) + rand() / (float)RAND_MAX * ((ScreenHeight - (2.5f * PlayerSize)) - (2.5 * PlayerSize));
			apple.sprite.setPosition(apple.position.x, apple.position.y);
	}
	void AppleRestart(AppleData& apple)
	{
		ReselectAppleNum(apple);
		for (int i = 0; i < apple.StandartApplesNum; ++i)
		{
			AppleRespawn(apple.Standart[i]);
		}
	}
}
