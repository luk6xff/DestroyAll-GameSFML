#pragma once
#include<SFML\Graphics.hpp>
#include "ResourceHolder.h"

namespace Textures
{
	enum ID
	{
		Landscape,
		Vehicle,
	};
}


struct Movement
{
	bool mIsMovingUp = { false };
	bool mIsMovingDown = { false };
	bool mIsMovingRight = { false };
	bool mIsMovingLeft = { false };
};


class Game
{
public:
	Game();
	~Game();
	void run();

private:
	static const float		PlayerSpeed;
	static const sf::Time	TimePerFrame;
	void handlePlayerInput(sf::Keyboard::Key, bool isPressed);
	void processEvents();
	void update(sf::Time elapsedTime);
	void render();

private:
	Movement mMovementDirection;
	ResourceHolder<sf::Texture, Textures::ID> mTextures;
	sf::RenderWindow mWindow;
	sf::Sprite mPlayer;

};

