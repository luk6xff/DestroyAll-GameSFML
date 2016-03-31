#pragma once
#include<SFML\Graphics.hpp>


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
	sf::RenderWindow mWindow;
	sf::Texture mTexture;
	sf::Sprite mPlayer;

};

