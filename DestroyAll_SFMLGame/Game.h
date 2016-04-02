#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

#include "World.h"


class Game
{
public:
	Game();
	~Game();
	void run();

private:
	static const sf::Time	TimePerFrame;
	void handlePlayerInput(sf::Keyboard::Key, bool isPressed);
	void processEvents();
	void update(sf::Time elapsedTime);
	void updateStatistics(sf::Time elapsedTime);
	void render();

private:

	sf::RenderWindow mWindow;
	World					mWorld;
	sf::Font				mFont;
	sf::Text				mStatisticsText;
	sf::Time				mStatisticsUpdateTime;
	std::size_t				mStatisticsNumFrames;

};

