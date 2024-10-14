// libraries
#include "SFML/Graphics.hpp"
#include "menu.h"
#include "constants.h"
#include "Game.h"
int main()
{
	//init
	srand((int)time(nullptr));
	using namespace AppleGame; 
	GameState game;

	
	
	while (true)//while to have a way to go back into the menu loop
	{

		//menu 
			std::string mode;
			std::cout << "choose a gameMode [standart,without apple respawn, without acceleretion, immortal]:\n";
			std::cin >> mode;
			
			
			if (mode == "standart")
			{
				game.mode = GameMode::standart;
				std::cout << " chosen the standart mode";
			}
			else if (mode == "without apple respawn")
			{
				game.mode = GameMode::withoutAppleRespawn;
				std::cout << " chosen the without apple respawn mode";
			}
			else if (mode == "without acceleretion")
			{
				game.mode = GameMode::withoutAcceleration;
				std::cout << " chosen the without accelertion mode";
			}
			else if (mode == "immortal")
			{
				game.mode = GameMode::immortal;
				std::cout << " chosen the immortal mode";
			}
			else
			{
				game.mode = GameMode::standart;
				std::cout << " the input was unclear \n chosen the standart mode";
			}
				
		//main loop
		GameInit(game);
		sf::Clock GameClock;
		float LastTime = GameClock.getElapsedTime().asSeconds();
		float CurrectTime = 0;
		float DeltaTime;
		bool soundPlayed = false;
		sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "YabloCHki");
		while (true)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				break;
			}
			//calculating time
			CurrectTime = GameClock.getElapsedTime().asSeconds();
			DeltaTime = CurrectTime - LastTime;
			LastTime = CurrectTime;
			if (game.status.IsGameOver)
			{
				if (!soundPlayed)
				{
					game.statistic.PlayTimeAsSeconds = GameClock.getElapsedTime().asSeconds();
					GameClock.restart();
					CurrectTime = 0;
					LastTime = 0;
					DeltaTime = 0;
					PlayTimeSaving(game.statistic.PlayTimeAsSeconds);
					GameLose(window, game.ui.font.font, game.ui.Audio.Sounds.death, game.data.player.Player.statistic.Score, game.data.player.Player.statistic.speed, game.statistic.playTime);
					soundPlayed = true;
				}
				else
				{
					float dealay;
					dealay = GameClock.getElapsedTime().asSeconds();
					if (dealay >= 5)
					{
						soundPlayed = false;
						game.status.IsGameOver = false;
					}
				}
			}			

			else
			{
				GameUpdate(GameClock, game, DeltaTime);
				DrawGame(window, game.ui, game.data);
			}
			//
		}
	}
	//deinit

	
    return 0;
}
