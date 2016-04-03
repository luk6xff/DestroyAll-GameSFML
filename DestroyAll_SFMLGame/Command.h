#pragma once
#include "Category.h"

#include <SFML/System/Time.hpp>

#include <functional>
#include <cassert>


class Entity;

class Command
{
public:
	Command();

	std::function<void(Entity&, sf::Time)>	action;
	unsigned int category;
	~Command();
};

template <typename GameObject, typename Function>
std::function<void(Entity&, sf::Time)> derivedAction(Function fn)
{
	return [=](Entity& entity, sf::Time dt)
	{
		// Check if cast is safe
		assert(dynamic_cast<GameObject*>(&entity) != nullptr);

		// Downcast node and invoke function on it
		fn(static_cast<GameObject&>(entity), dt);
	};
}