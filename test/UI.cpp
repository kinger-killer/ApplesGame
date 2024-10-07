#include "UI.h"
#include "Game.h"

void AppleGame::LoseScreenInit(LoseScreen& lose, sf::Font& font, const int score, const float speed, Time Play)
{
	//back
	lose.back.setFillColor(sf::Color::Red);
	SetRectangleShapeSize(lose.back, ScreenWidth, ScreenHeight);
	SetRectangleShapeOrigen(lose.back, { 0.5,0.5 });
	//luse label
	TextInit(lose.LuseLabel, font, 48, { ScreenWidth / 2, 75 }, "YOU LOSE");
	//score label
	TextInit(lose.ScoreStatistic, font, 24, { ScreenWidth / 2, 250 }, "your score is:" + score);
	//instruction label
	TextInit(lose.InstructionLabel, font, 24, { 45, 550 }, "press 'r' to restart and esc to escape");
	//speed label 
	TextInit(lose.PlayerSpeed, font, 25, { ScreenWidth / 2, 350 }, "youre final speed is equel to " + std::to_string(speed) + " pixels per second");
	//time label
	std::string time;
	Time play;
	time = std::to_string(play.MiliSec) + "miliseconds";
	if (Play.sec >= 1)
	{
		time = time + "," + std::to_string(play.sec) + "seconds";
		if (Play.min >= 1)
		{
			time = time + "," + std::to_string(play.min) + "minutes";
			if (Play.hrs >= 1)
			{
				time = time + "and " + std::to_string(play.hrs) + "hours. WoW";
			}
		}
	}
	time = "your play time is:" + time;
	TextInit(lose.TimeStatistic, font, 24, { ScreenWidth / 2, 300 }, time);

}

void AppleGame::DrawLoseScreen(sf::RenderWindow& window, LoseScreen& lose)
{
	window.draw(lose.back);
	window.draw(lose.LuseLabel);
	window.draw(lose.ScoreStatistic);
	window.draw(lose.TimeStatistic);
	window.draw(lose.InstructionLabel);
	window.draw(lose.PlayerSpeed);
	window.display();
}

void AppleGame::UiInit(GameUi& ui, sf::Font& font)
{
	TextInit(ui.PlayerSpeedLable, font, 24, { 650, 25 }, "uwu");
	TextInit(ui.ScoreLable, font, 24, { 650, 50 }, "uwu");
}

void AppleGame::DrawGame(sf::RenderWindow& window, Recurces& recurces, Dataes& data)
{
	window.clear();
	window.draw(data.player.Player.sprite);
	for (int i = 0; i < data.lemon.LemonzNum; ++i)
	{
		window.draw(data.lemon.lemon[i].sprite);
	}
	for (int i = 0; i < data.apple.StandartApplesNum; ++i)
	{
		window.draw(data.apple.Standart[i].sprite);
	}
	UpdateGameUi(recurces.texts, data.player.Player.statistic);
	window.display();
}
