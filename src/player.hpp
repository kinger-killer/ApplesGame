#pragma once 

#include <SFML/Graphics.hpp>

#include <iostream>

#include "../Tools/AssetsManager.hpp"
#include "Entity.hpp"

const sf::Vector2f PLAYER_SIZE = { 20,20 };

enum PlayerDirection
{
	left,
	up,
	right,
	down
};

class player : public Entity
{
public:
	player( sf::Vector2f position = { 0.0f,0.0f }, float velocity = 1)
		: Entity( "player", position, PLAYER_SIZE), vel(velocity)
	{}

	void Update(float deltaTime) //as miliSeconds
	{
		for (int i = 0; i < 4; ++i)
		{
			if (sf::Keyboard::isKeyPressed(keys[i]))
			{
				dir = static_cast<PlayerDirection>(i);
			 
				sf::Vector2f direction = getDirection();
				if (direction.x == 0)
				{
					setRotation(90);
					if (direction.y < 0)
						setScale({ -scale.x,scale.y });
					else
						setScale(scale);
				}
				else
				{
					setRotation(0);
					if (direction.x < 0)
						setScale({ -scale.x,scale.y });
					else
						setScale(scale);
				}
			}
		}

		sf::Vector2f newPosition(vel * deltaTime * getDirection());
		newPosition += getPosition();
		setPosition(newPosition);
	}


private:
	
	sf::Vector2f getDirection()
	{
		switch (dir)
		{
		case left:
			return { -1,0 };
		case up:
			return { 0,-1 };
		case right:
			return { 1,0 };
		case down:
			return { 0,1 };
		}
		return{ 0,0 };
	}

	sf::Keyboard::Key keys[4] =
	{
		sf::Keyboard::Key::A,
		sf::Keyboard::Key::W,
		sf::Keyboard::Key::D,
		sf::Keyboard::Key::S
	};

	sf::Vector2f scale = PLAYER_SIZE;

	PlayerDirection dir = PlayerDirection::right;
	float vel;
};