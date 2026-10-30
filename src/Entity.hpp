#pragma once

#include <SFML/Graphics.hpp>

#include <string>

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
	}
	
	virtual void Render(sf::RenderWindow& window)
	{
		window.draw(body);
	}

protected:
	
	static sf::Texture& requireTexture(const std::string& name)
	{
		auto* texture = AssetsManager::getInstance().getTexture(name);

		if (!texture)
			throw std::runtime_error("Texture not found: " + name);

		return *texture;
	}

	void setPosition(sf::Vector2f pos)
	{
		position = pos;
		body.setPosition(position);
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
};
