#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include "../Tools/AssetsManager.hpp"

class Entity
{
public:
	Entity(std::string textureName, sf::Vector2f pos = { 0.0f,0.0f }, sf::Vector2f size = { 0.0f,0.0f })
		: body(requireTexture(textureName)), position(pos), scale(size)
	{
		sf::FloatRect bounds = body.getLocalBounds();
		if (scale.x >= 0.0f && scale.y >= 0.0f)
		{
			
			float XScale = scale.x / bounds.size.x;
			float YScale = scale.y / bounds.size.y;
			body.setScale({XScale,YScale});
		}
		
		body.setOrigin({ bounds.size.x / 2,bounds.size.y / 2 });
		body.setPosition(position);

		BoundsInit(position, body.getGlobalBounds().size);
	}
	
	virtual void Render(sf::RenderWindow& window)
	{
		window.draw(body);
	}

	virtual void Update(float deltaTime) = 0;

protected:

	sf::RectangleShape& getRectBounds()
	{
		return rectBounds;
	}

	sf::CircleShape& getCircleBounds()
	{
		return circleBounds;
	}

	void setPosition(sf::Vector2f pos)
	{
		position = pos;
		body.setPosition(position);
		rectBounds.setPosition(position);
		circleBounds.setPosition(position);
	}
	[[nodiscard]] sf::Vector2f getPosition()
	{
		return position;
	}

	void setScale(sf::Vector2f size)
	{
		scale = size;

		if (scale.x != 0.0f && scale.y != 0.0f)
		{
			sf::FloatRect bounds = body.getLocalBounds();

			float XScale = scale.x / bounds.size.x;
			float YScale = scale.y / bounds.size.y;

			body.setScale({ XScale,YScale });
		}
	}

	[[nodiscard]] sf::Vector2f getScale()
	{
		return scale;
	}

	void setRotation(float angle)
	{
		body.setRotation(sf::degrees(angle));
	}
private:
	sf::Vector2f position;
	sf::Vector2f scale;
	sf::Sprite body;

	sf::CircleShape circleBounds;
	sf::RectangleShape rectBounds;


	static sf::Texture& requireTexture(const std::string& name)
	{
		auto* texture = AssetsManager::getInstance().getTexture(name);

		if (!texture)
			throw std::runtime_error("Texture not found: " + name);

		return *texture;
	}

	void BoundsInit(sf::Vector2f position, sf::Vector2f scale)
	{
		//circle bounds init;
		circleBounds.setRadius((scale.x / 2 + scale.y / 2) / 2);
		circleBounds.setOrigin({ scale.x / 2,scale.y / 2 });
		circleBounds.setPosition(position);

		//rectangle bounds init
		auto rb = circleBounds.getLocalBounds();
		float rectangleDeltaX = scale.x / rb.size.x;
		float rectangleDeltaY = scale.y / rb.size.y;

		rectBounds.setScale({ rectangleDeltaX,rectangleDeltaY });
		rectBounds.setOrigin({ scale.x / 2,scale.y / 2 });
		rectBounds.setPosition(position);
	}
};
