#include "Game.h"
#include "assert.h"


namespace AppleGame
{
	bool DoesTextureLoaded(Recurces& ui)
	{
		return ((ui.apple.StandartAppleTexTure.loadFromFile(RecurcesPath + "StandartApple.png")) &&
				(ui.player.PlayerTexture.loadFromFile(RecurcesPath + "FPlayer.png"))&&
				(ui.lemon.lemon.loadFromFile(RecurcesPath + "lemonz.png")));
	}

	bool DoesSoundsLoaded(SoundBuffers& buffer)
	{
		return ((buffer.death.loadFromFile(RecurcesPath + "Death.wav")) && (buffer.eat.loadFromFile(RecurcesPath + "AppleEat.wav")));
	}

	bool DoesFontsLoaded(Fonts& fonts)
	{
		return ((fonts.font.loadFromFile(RecurcesPath + "Fonts/Roboto-BoldItalic.ttf")));
	}

	void GameInit(GameState& game)
	{
		//loading recurces
		int i = 0;
		//loading the textures
		while (!DoesTextureLoaded(game.ui))
		{
			if (i <= 3)
			{
				std::cout << "textures loading failed";
				assert(false);
			}
				++i;
		}
		//loading the sounds
		i = 0;
		while (!DoesSoundsLoaded(game.ui.buffers))
		{
			if (i <= 3)
			{
				std::cout << "sounds loading failed";
				assert(false);
			}
				++i;		
		}
		game.ui.sounds.eat.setBuffer(game.ui.buffers.eat);
		game.ui.sounds.death.setBuffer(game.ui.buffers.death);
		//loading the fonts
		i = 0;
		while (!DoesFontsLoaded(game.ui.font))
		{
			if (i <= 3)
			{
				std::cout << "sounds loading failed";
				assert(false);
			}
			++i;
		}
		//apples init
		AppleInit(game.data.apple);
		for (int i = 0; i < game.data.apple.StandartApplesNum; ++i)
		{
			game.data.apple.Standart[i].sprite.setTexture(game.ui.apple.StandartAppleTexTure);			
		}

		//player init
		game.data.player.Player.sprite.setTexture(game.ui.player.PlayerTexture);
		PlayerInit(game.data.player.Player);
		//lemonz init
		LemonzInit(game.data.lemon);
		for (int i = 0; i < game.data.lemon.LemonzNum; ++i)
		{
			game.data.lemon.lemon[i].sprite.setTexture(game.ui.lemon.lemon);
		}
		//init interface
			
	}

	void GameRestart(Player& player, AppleData& apple, LemonData& lemon)
	{
		RestartPlayer(player);
		AppleRestart(apple);
		lemonzrestart(lemon);
	}

	PlayerDirection GameImputReading(PlayerDirection& current)
	{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
		{
			return PlayerDirection::Right;
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
		{
			return PlayerDirection::Up;
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
		{
			return PlayerDirection::left;
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
		{
			return PlayerDirection::Down;
		}
		else
		{
			return current;
		}
	}

	void GameLose(sf::RenderWindow& window, sf::Font& font, sf::Sound& sound, const int score, const int speed, const Time time)
	{
			window.clear();
			LoseScreen screen;
			LoseScreenInit(screen, font, score, speed, time);
			DrawLoseScreen(window, screen);
			PlaySound(sound);	
	}

	void UpdateGameUi(Textes& texts, PlayerStatistic& statistic)
	{
		texts.score.setString("score:" + statistic.Score);
		texts.speed.setString("speed:" + statistic.speed);
	}
	void BorderPortal(PlayerData& player)
	{
		if (player.Player.position.x >= ScreenWidth)
		{
			player.Player.position.x = 0;
		}
		else if (player.Player.position.x <= 0)
		{
			player.Player.position.x = ScreenWidth;
		}
		else if (player.Player.position.y >= ScreenHeight)
		{
			player.Player.position.y = 0;
		}
		else if (player.Player.position.y <= 0)
		{
			player.Player.position.y = ScreenHeight;
		}
	}

	void GameUpdate(sf::Clock& clock, GameState& game, float DeltaTime)
	{
		game.input.direction = GameImputReading(game.input.direction);
		PlayerMovement(game.data.player.Player, DeltaTime);

		std::cout << "player posion:" + game.data.player.Player.position.x + "," + game.data.player.Player.position.y;
		if (game.mode != GameMode::withoutAcceleration)
		{
			game.data.player.Player.statistic.speed += AccelerationByTime * DeltaTime;
		}
		CheckForApples(game.data.player, game.data.apple, game.ui.sounds.eat, game.mode);
		game.status.IsGameOver = ((CheckBorders(game.data.player.Player)) || (CheckForLemonz(game.data.player.Player, game.data.lemon)) && game.mode != GameMode::immortal);
		if (CheckBorders(game.data.player.Player) || game.mode == GameMode::immortal)
		{
			BorderPortal(game.data.player);
		}

	}

}