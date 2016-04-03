#include "World.h"



World::World(sf::RenderWindow& window)
	: mWindow(window)
	//, mWorldView(window.getDefaultView())
	, mTextures()
	, mEntities()
	, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, mWorldView.getSize().y)
	, mPlayerTank(nullptr)
{
	loadTextures();
	buildScene();
	mWorldView.setCenter(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f);

}


World::~World()
{
	for (Entity* entity : mEntities) {
		delete entity;
	}
}


void World::update(sf::Time dt)
{

	mPlayerTank->setVelocity(0.f, 0.f);

	// Forward commands to scene graph, adapt velocity (scrolling, diagonal correction)
	while (!mCommandQueue.isEmpty())
		mPlayerTank->onCommand(mCommandQueue.pop(), dt);
	adaptPlayerVelocity();

	// Regular update step, adapt position (correct if outside view)
	// Apply movements
	for (Entity* entity : mEntities) {
		entity->update(dt);
	}
	adaptPlayerPosition();
}
void World::draw()
{
	mWindow.setView(mWorldView);
	
	for (const Entity* entity : mEntities)
		mWindow.draw(*entity);
}

CommandQueue& World::getCommandQueue()
{
	return mCommandQueue;
}

void World::loadTextures()
{
	mTextures.load(Textures::PlayerTank, "Media/Textures/tanksprite.png", sf::IntRect(0, 0, 16, 16));
	mTextures.load(Textures::EnemyTank, "Media/Textures/tanksprite.png", sf::IntRect(128, 128, 16, 16));
	mTextures.load(Textures::BackgorundTexture, "Media/Textures/Desert.png");
}

void World::buildScene()
{

	// Prepare the tiled background
	sf::Texture& texture = mTextures.get(Textures::BackgorundTexture);
	sf::IntRect textureRect(mWorldBounds);
	texture.setRepeated(true);

	// Add the background sprite to the scene
	Background *backgroundSprite =new Background(texture, textureRect);
	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	mEntities.push_back(backgroundSprite);

	// Add player's Tank
	mPlayerTank = new Tank(Tank::Player, mTextures);
	mPlayerTank->setPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f);
	mPlayerTank->setVelocity(40.f, -50);
	mEntities.push_back(mPlayerTank);

	// Add enemy's Tank
	mEnemyTank = new Tank(Tank::Enemy, mTextures);
	mEnemyTank->setPosition(1000.f, 240.f);
	mPlayerTank->setVelocity(300.f, 300.f);
	mEntities.push_back(mEnemyTank);
}

void World::adaptPlayerPosition()
{
	// Keep player's position inside the screen bounds, at least borderDistance units from the border
	sf::FloatRect viewBounds(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
	const float borderDistance = 40.f;

	sf::Vector2f position = mPlayerTank->getPosition();
	position.x = std::max(position.x, viewBounds.left + borderDistance);
	position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
	position.y = std::max(position.y, viewBounds.top + borderDistance);
	position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
	mPlayerTank->setPosition(position);
}

void World::adaptPlayerVelocity()
{
	sf::Vector2f velocity = mPlayerTank->getVelocity();

	// If moving diagonally, reduce velocity (to have always same velocity)
	if (velocity.x != 0.f && velocity.y != 0.f)
		mPlayerTank->setVelocity(velocity / std::sqrt(2.f));

	// Add scrolling velocity
	mPlayerTank->accelerate(0.f, 10);
}