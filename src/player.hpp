#pragma once 

#include <SFML/Graphics.hpp>

#include <iostream>

const sf::Vector2f PLAYER_SIZE = { 20,20 };

enum PlayerDirection
{
	left,
	up,
	right,
	down
};

class player
{
public:
	player(sf::Vector2f position = {0.0f,0.0f}, float velocity = 100) : pos(position), vel(velocity)
	{
		body.setSize(PLAYER_SIZE);
		body.setOrigin({ PLAYER_SIZE.x / 2,PLAYER_SIZE.y / 2 });
		body.setPosition(pos);
		body.setFillColor({ 150,30,20 });
	}

	void Update(float deltaTime) //as miliSeconds
	{
		for (int i = 0; i < 4; ++i)
		{
			if(sf::Keyboard::isKeyPressed(keys[i]))
				dir = static_cast<PlayerDirection>(i);
		}

		deltaTime /= 1000;

		pos += vel * deltaTime * getDirection();
		body.setPosition(pos);

	}

	void Render(sf::RenderWindow& window)
	{
		window.draw(body);
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

	sf::RectangleShape body;

	PlayerDirection dir = PlayerDirection::right;
	sf::Vector2f pos;
	float vel;
};