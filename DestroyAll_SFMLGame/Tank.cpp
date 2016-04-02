#include "Tank.h"
#include "ResourceHolder.h"

Textures::ID toTextureID(Tank::Type type)
{
	switch (type)
	{
	case Tank::Player:
		return Textures::PlayerTank;

	case Tank::Enemy:
		return Textures::EnemyTank;
	}
	return Textures::PlayerTank;
}

Tank::Tank(Type type, const TextureHolder& textures):mType(type), mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}


void Tank::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

Tank::~Tank()
{
}
