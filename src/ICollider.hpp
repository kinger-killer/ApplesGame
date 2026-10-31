#pragma once 

#include <SFML/Graphics.hpp>

#include <optional>
#include <algorithm>
class ICollider
{
public:
	virtual sf::Shape& getCollider() = 0;
	bool checkCollision(ICollider& Collider)
	{
		if (intersectsWith(Collider))
		{
			this->onHit();
			Collider.onHit();

			return true;
		}
		return false;
	}

	virtual ~ICollider() = default;
protected:
	virtual void onHit() = 0;
private:
	bool intersectsWith(ICollider& Collider)
	{
		const sf::Shape& firstShape = this->getCollider();
		const sf::Shape& secondShape = Collider.getCollider();

		sf::FloatRect bounds1 = firstShape.getGlobalBounds();
		sf::FloatRect bounds2 = secondShape.getGlobalBounds();

		if (bounds1.findIntersection(bounds2).has_value())
		{
			const auto* circle1 = dynamic_cast<const sf::CircleShape*>(&firstShape);
			const auto* circle2 = dynamic_cast<const sf::CircleShape*>(&secondShape);

			sf::Vector2f center1 = bounds1.position + (bounds1.size / 2.f);
			sf::Vector2f center2 = bounds2.position + (bounds2.size / 2.f);

			if (circle1 && circle2)
			{
				float distanceX = center1.x - center2.x;
				float distanceY = center1.y - center2.y;
				float radiusSum = (circle1->getRadius() + circle2->getRadius());

				float distanceSquered = distanceX * distanceX + distanceY * distanceY;

				return (distanceSquered <= (radiusSum * radiusSum));
			}
			else if (!circle1 && !circle2)
				return true;
			else
			{
				const sf::CircleShape* circle;
				const sf::FloatRect* squere;
				sf::Vector2f circleCenter;

				if (circle1)
				{
					circle = circle1;
					squere = &bounds2;
					circleCenter = center1;
				}
				else
				{
					circle = circle2;
					squere = &bounds1;
					circleCenter = center2;
				}
				const float circleRadius = circle->getRadius();

				sf::FloatRect squereBounds = *squere;
				float boxMinX = squereBounds.position.x;
				float boxMaxX = squereBounds.position.x + squereBounds.size.x;
				float boxMinY = squereBounds.position.y;
				float boxMaxY = squereBounds.position.y + squereBounds.size.y;
				
				sf::Vector2f closestPoint;
				//locking x
				closestPoint.x = std::clamp(circleCenter.x, boxMinX, boxMaxX);
				//locking y
				closestPoint.y = std::clamp(circleCenter.y, boxMinY, boxMaxY);

				float distanceX = circleCenter.x - closestPoint.x;
				float distanceY = circleCenter.y - closestPoint.y;

				float distanceSquered = (distanceX * distanceX) + (distanceY * distanceY);

				return distanceSquered <= (circleRadius * circleRadius);
			}
		}
		
		return false;
	}
};