#include "Math.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

namespace AppleGame
{
    Time PlayTimeSaving(const float PlayTime)
    {
        Time Result;
        Result.MiliSec = PlayTime - (int)(PlayTime / 1);
        Result.sec = (int)(PlayTime / 1);
        Result.min = PlayTime - 60 * (int)((PlayTime - (int)(PlayTime / 1)) / 60);
        Result.hrs = PlayTime - 3600 * (int)((PlayTime - (int)(PlayTime / 1)) / 3600);
        return Result;
    }
    void TextInit(sf::Text& string, sf::Font& font, int textSize, pos2d textPosition, std::string text)
    {
        string.setFont(font);
        string.setCharacterSize(textSize);
        string.setFillColor(sf::Color::White);
        string.setOrigin(string.getLocalBounds().width / 2.0f, string.getLocalBounds().height / 2.0f);
        string.setPosition(textPosition.x, textPosition.y);
        string.setString(text);
    }
    bool IsCollisionCollaied(pos2d firstObjectPosition, int firstObjectSize, pos2d secondObjectPosition, int secondObjectSize)
    {
        bool result;
        float squereDistance = (fabs(firstObjectPosition.x - secondObjectPosition.x)) * (fabs(firstObjectPosition.x - secondObjectPosition.y)) +
            (fabs(firstObjectPosition.y - secondObjectPosition.y)) * (fabs(firstObjectPosition.y - secondObjectPosition.y));
        float squereSize = (firstObjectSize + secondObjectSize) * (firstObjectSize + secondObjectSize);
        result = (squereDistance <= squereSize);
        return result;
    }

    void SetSpriteSize(sf::Sprite& sprite, float desiredWeight, float desiredHeight)
    {
        sf::FloatRect spriteRect = sprite.getLocalBounds();
        sf::Vector2f scale = { desiredWeight / spriteRect.width, desiredHeight / spriteRect.height };
        sprite.setScale(scale);
    }
    void SetSpriteRelativeOrigen(sf::Sprite& sprite, pos2d origin)
    {
        sf::FloatRect spriteRect = sprite.getLocalBounds();
        sprite.setOrigin(origin.x * spriteRect.width, origin.y * spriteRect.height);
    }
    void SetRectangleShapeSize(sf::RectangleShape& shape, float desiredWeight, float desiredHeight)
    {
        sf::FloatRect ShapeRect = shape.getLocalBounds();
        sf::Vector2f scale = { desiredWeight / ShapeRect.width, desiredHeight / ShapeRect.height };
        shape.setScale(scale);
    }
    void SetRectangleShapeOrigen(sf::RectangleShape& shape, pos2d origin)
    {
        sf::FloatRect spriteRect = shape.getLocalBounds();
        shape.setOrigin(origin.x * spriteRect.width, origin.y * spriteRect.height);
    }
    void PlaySound(sf::Sound& sound)
    {
        sound.play();
    }
    void DrawText(sf::RenderWindow& window, sf::Text& text)
    {
        window.draw(text);
    }
}