#include "Lemon.h"

void AppleGame::ReselectLemonNum(LemonData& data)
{
	delete[] data.lemon;
	data.LemonzNum = (int)(MinimumLemonzNum + rand() / (float)(RAND_MAX) * (MaximumLemonzNum - MinimumLemonzNum));
	data.lemon = new Lemon[data.LemonzNum];
}

void AppleGame::LemonzInit(LemonData& data)
{
	for (int i = 0; i < data.LemonzNum; ++i)
	{
		SetSpriteRelativeOrigen(data.lemon[i].sprite, { 0.5f,0.5f });
		SetSpriteSize(data.lemon[i].sprite, LemonSize, LemonSize);
		data.lemon[i].position.x = (2.5 * PlayerSize) + rand() / (float)RAND_MAX * ((ScreenWidth - (2.5f * PlayerSize)) - (2.5 * PlayerSize));
		data.lemon[i].position.y = (2.5 * PlayerSize) + rand() / (float)RAND_MAX * ((ScreenHeight - (2.5f * PlayerSize)) - (2.5 * PlayerSize));
	}

}

void AppleGame::lemonzrestart(LemonData& data)
{
	ReselectLemonNum(data);
	for (int i = 0; i < data.LemonzNum; ++i)
	{
		data.lemon[i].position.x = (2.5 * PlayerSize) + rand() / (float)RAND_MAX * ((ScreenWidth - (2.5f * PlayerSize)) - (2.5 * PlayerSize));
		data.lemon[i].position.y = (2.5 * PlayerSize) + rand() / (float)RAND_MAX * ((ScreenHeight - (2.5f * PlayerSize)) - (2.5 * PlayerSize));
		data.lemon[i].sprite.setPosition(data.lemon[i].position.x, data.lemon[i].position.y);
	}
}

void AppleGame::DrawLemonz(LemonData& data, sf::RenderWindow& window)
{
	for (int i = 0; i < data.LemonzNum; ++i)
	{
		window.draw(data.lemon[i].sprite);
	}
}
