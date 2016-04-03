#pragma once
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "Tank.h"
#include "Background.h"
#include "Command.h"
#include "CommandQueue.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <list>
#include <array>

namespace sf
{
	class RenderWindow;
}

class World :private sf::NonCopyable
{
public:
	explicit World(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw();
	CommandQueue& getCommandQueue();
	~World();

private:
	void	loadTextures();
	void	buildScene();
	void	adaptPlayerPosition();
	void	adaptPlayerVelocity();

private:
	enum Layer
	{
		BackgroundLayer,
		GroundLayer,
		LayerCount
	};

private:
	sf::RenderWindow& mWindow;
	sf::View mWorldView;
	TextureHolder mTextures;
	std::list<Entity*> mEntities;
	std::array<Entity*, LayerCount> mSceneLayers;
	sf::FloatRect mWorldBounds;
	CommandQueue mCommandQueue;
	Tank* mPlayerTank;
	Tank* mEnemyTank;
};

