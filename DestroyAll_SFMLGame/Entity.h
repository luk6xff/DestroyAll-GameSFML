#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Command;

class Entity:public sf::Transformable, public sf::Drawable
{
public:
	Entity();
	~Entity();
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;
	void accelerate(sf::Vector2f velocity);
	void accelerate(float vx, float vy);
	virtual void update(sf::Time dt);

	void onCommand(const Command& command, sf::Time dt);
	virtual unsigned int	getCategory() const;


private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const =0;

private:
	sf::Vector2f mVelocity;

};

