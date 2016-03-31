#include "Game.h"
#include <iostream>


const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);


Game::Game():mWindow(sf::VideoMode(640,480),"DestroyAll by igbt6 (2015)"),mTexture(), mPlayer(), mMovementDirection()
{
	if (!mTexture.loadFromFile("Media/Textures/falcon.png"))
	{
		std::cout << "Media/Textures/falcon.png not found !!!!";
	}
	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(640/2.f, 480/2.f);
	mPlayer.setScale(0.4, 0.4);

}


Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen()) 
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
		if (key == sf::Keyboard::Up)
			mMovementDirection.mIsMovingUp = isPressed;
		else if (key == sf::Keyboard::Down)
			mMovementDirection.mIsMovingDown = isPressed;
		else if (key == sf::Keyboard::Left)
			mMovementDirection.mIsMovingLeft = isPressed;
		else if (key == sf::Keyboard::Right)
			mMovementDirection.mIsMovingRight = isPressed;
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				mWindow.close();
				break;
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;
		}

		if (event.type == sf::Event::Closed)
		{
			mWindow.close();
		}
	}
}

void Game::update(sf::Time elapsedTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (mMovementDirection.mIsMovingUp)
		movement.y -= PlayerSpeed;
	if (mMovementDirection.mIsMovingDown)
		movement.y += PlayerSpeed;
	if (mMovementDirection.mIsMovingLeft)
		movement.x -= PlayerSpeed;
	if (mMovementDirection.mIsMovingRight)
		movement.x += PlayerSpeed;
	mPlayer.move(movement* elapsedTime.asSeconds());

}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}
