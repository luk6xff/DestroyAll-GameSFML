#include "Game.h"
#include <iostream>
#include "ResourceHolder.h"
#include "StringHelpers.hpp"




const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);


Game::Game():mWindow(sf::VideoMode(640,480),"DestroyAll by igbt6 (2015)",sf::Style::Close),
  mWorld(mWindow)
, mFont()
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
{
	mFont.loadFromFile("Media/Fonts/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
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
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		updateStatistics(elapsedTime);
		render();
	}
}


void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Up)
	{

	}
	else if (key == sf::Keyboard::Down)
	{

	}
	else if (key == sf::Keyboard::Left)
	{

	}
	else if (key == sf::Keyboard::Right)
	{
	}
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
	mWorld.update(elapsedTime);
}

void Game::render()
{
	mWindow.clear();
	mWorld.draw();
	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

