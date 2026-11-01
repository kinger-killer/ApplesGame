#pragma once

#include <vector>
#include <memory>
#include <algorithm>

#include <iostream>

#include "Randomizer.hpp"

#include "apple.hpp"




class AppleManager : private IObserver
{
public:
	AppleManager(sf::Vector2f gamefield, uint16_t num)
		: observerHandle(static_cast<IObserver*>(this), [](IObserver*) {})
	{
		for (uint16_t i = 0; i < num; i++)
		{
			Apples_m.push_back(std::make_unique<Apple>(sf::Vector2f{
				random<float>(0, gamefield.x), random<float>(0, gamefield.y)}));
			Apples_m.back()->subscribe(observerHandle);
		}
	}

	void Render(sf::RenderWindow& window)
	{
		for (const auto& apple : Apples_m)
		{
			apple->Render(window);
		}
	}

	void checkCollision(ICollider& player)
	{
		for (const auto& apple : Apples_m)
		{
			apple->checkCollision(player);
		}

		removeEaten();
	}

	void notify(Event& event) override
	{
		std::cout << "+1 point\n";
		auto* appleEvent = dynamic_cast<AppleEvent*>(&event);
		if (!appleEvent)
			return;

		Apple* sender = appleEvent->sender;

		auto it = std::find_if(Apples_m.begin(), Apples_m.end(),
			[sender](const auto& apple) {
				return apple.get() == sender;
			});

		if (it != Apples_m.end() && std::find(eaten.begin(), eaten.end(), sender) == eaten.end())
			eaten.push_back(sender);
	}

private:
	std::shared_ptr<IObserver> observerHandle;
	std::vector<std::unique_ptr<Apple>> Apples_m;
	std::vector<Apple*> eaten;

	void removeEaten()
	{
		Apples_m.erase(std::remove_if(Apples_m.begin(), Apples_m.end(), [this](const auto& apple) {
			return std::find(eaten.begin(), eaten.end(), apple.get()) != eaten.end();
		}), Apples_m.end());

		eaten.clear();
	}
};
