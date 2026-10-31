#pragma once 

#include <SFML/Graphics.hpp>

#include "ICollider.hpp"
#include "Observer.hpp"

#include "entity.hpp"

const sf::Vector2f APPLE_SIZE = { 20,20 };

class Apple : public Entity, public ICollider, public ISubject 
{
public:
	Apple(sf::Vector2f position = { 0.0f,0.0f })
		: Entity("apple", position, APPLE_SIZE)
	{}

	virtual void Update(float deltaTime) {};


	virtual sf::Shape& getCollider() override
	{
		return getCircleBounds();
	}
private:
	virtual void onHit() override
	{
		Event event;
		Emit(event);
	}

};