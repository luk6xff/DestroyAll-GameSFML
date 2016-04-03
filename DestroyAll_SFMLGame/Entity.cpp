#include "Entity.h"
#include "Category.h"
#include "Command.h"

Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::setVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	mVelocity.x= vx;
	mVelocity.y = vy;
}


sf::Vector2f Entity::getVelocity() const
{
	return mVelocity;
}

void Entity::update(sf::Time dt)
{
	move(mVelocity*dt.asSeconds());
}

void Entity::accelerate(sf::Vector2f velocity)
{
	mVelocity += velocity;
}

void Entity::accelerate(float vx, float vy)
{
	mVelocity.x += vx;
	mVelocity.y += vy;
}


void Entity::onCommand(const Command& command, sf::Time dt)
{
	// Command current node, if category matches
	if (command.category & getCategory())
		command.action(*this, dt);
}

unsigned int Entity::getCategory() const
{
	return Category::Scene;
}
