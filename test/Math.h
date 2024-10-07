#pragma once
#include "string"
namespace sf
{
    struct Text;
    struct Font;
    struct Sprite;
    struct Sound;
    struct RenderWindow;
    struct RectangleShape;
}
namespace AppleGame
{
    struct pos2d
    {
        float x, y = 0;
    };
    struct Time
    {
        int MiliSec = 0;
        int sec = 0;
        int min = 0;
        int hrs = 0;

    };
    Time PlayTimeSaving(const float PlayTime);
    void TextInit(sf::Text& string, sf::Font& font, int textSize, pos2d textPosition, std::string text);
    bool IsCollisionCollaied(pos2d firstObjectPosition, int firstObjectSize, pos2d secondObjectPosition, int secondObjectSize);
    void SetSpriteSize(sf::Sprite& sprite, float desiredWeight, float desiredHeight);
    void SetSpriteRelativeOrigen(sf::Sprite& sprite, pos2d origin);
    void SetRectangleShapeSize(sf::RectangleShape& shape,float desiredWeight, float desiredHeight);
    void SetRectangleShapeOrigen(sf::RectangleShape& shape, pos2d origin);
    void PlaySound(sf::Sound& sound);
    void DrawText(sf::RenderWindow& window, sf::Text& text);
}