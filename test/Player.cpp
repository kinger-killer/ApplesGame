#include "Player.h"
#include "Game.h"
namespace AppleGame
{

    void PlayerInit(Player& player)
    {
        SetSpriteSize(player.sprite, PlayerSize, PlayerSize);
        SetSpriteRelativeOrigen(player.sprite, { 0.5,0.5 });
        player.direction = PlayerDirection::Right;
        player.position = { ScreenWidth / 2, ScreenHeight / 2 };
        player.sprite.setPosition(player.position.x, player.position.y);
        player.statistic.speed = InitialSpeed;
        
    }

    void RestartPlayer(Player& player)
    {
        player.position = { ScreenWidth / 2.0f, ScreenHeight / 2.0f };
        player.statistic.speed = InitialSpeed;
        player.sprite.setPosition(player.position.x, player.position.y);
    }

    void PlayerMovement(Player& player, float deltaTime)
    {
        if (player.direction == PlayerDirection::Right)
        {
            player.position.x += player.statistic.speed * deltaTime;
            player.sprite.setRotation(0);
        }
        else if (player.direction == PlayerDirection::Up)
        {
            player.position.y -= player.statistic.speed * deltaTime;
            player.sprite.setRotation(270);
        }
        else if (player.direction == PlayerDirection::left)
        {
            player.position.x -= player.statistic.speed * deltaTime;
            player.sprite.setRotation(180);
        }
        else if (player.direction == PlayerDirection::Down)
        {
            player.position.y += player.statistic.speed * deltaTime;
            player.sprite.setRotation(90);
        }
        player.sprite.setPosition(player.position.x, player.position.y);
    }

    void CheckForApples(PlayerData& data, AppleData& apple, Sounds& sound, const GameMode& mode)
    {
        for (int i = 0; i < apple.StandartApplesNum; ++i)
        {
            //colculating the squere distance
            float squareDistance = (data.Player.position.x - apple.Standart[i].position.x) * (data.Player.position.x - apple.Standart[i].position.x) +
                (data.Player.position.y - apple.Standart[i].position.y) * (data.Player.position.y - apple.Standart[i].position.y);
            //colculating the squere collision size
            float squareRadiusSum = (AppleSize + PlayerSize) * (AppleSize + PlayerSize) / 4;
            //checking collisions
            if (squareDistance <= squareRadiusSum)
            {
                ++data.Player.statistic.Score;
                if (mode != GameMode::withoutAppleRespawn)
                {
                    AppleRespawn(apple.Standart[i]);
                }
                PlaySound(SoundType::eat, sound);
                if (mode != GameMode::withoutAcceleration)
                { 
                data.Player.statistic.speed += AcceleretionByEatenApples;
                }
            }
        }
    }

    bool CheckForLemonz(Player& player, LemonData& lemonz)
    {
        bool result = false;
        for (int i = 0; i < lemonz.LemonzNum; ++i)
        {
            float squareDistance = (player.position.x - lemonz.lemon[i].position.x) * (player.position.x - lemonz.lemon[i].position.x) +
                (player.position.y - lemonz.lemon[i].position.y) * (player.position.y - lemonz.lemon[i].position.y);

            float squareRadiusSum = (LemonSize + PlayerSize) * (LemonSize + PlayerSize) / 4;

            if (squareDistance <= squareRadiusSum)
            {
                result = true;
                break;
            }
        }
        return result;
    }
    bool CheckBorders(Player& player)
    {
        return (player.position.x - PlayerSize <= 0 || player.position.x + PlayerSize >= ScreenWidth
            || player.position.y - PlayerSize <= 0 || player.position.y + PlayerSize >= ScreenHeight);

    }
    void DrawPlayer(Player& player, sf::RenderWindow& window)
    {
        DrawSpraite(window, player.sprite);
    }  
}