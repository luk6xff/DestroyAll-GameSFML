#include "Background.h"
#include "ResourceHolder.h"



Background::Background(const sf::Texture& texture): mSprite(texture)
{
}

Background::Background(const sf::Texture& texture, const sf::IntRect& textureRect)
	: mSprite(texture, textureRect)
{
}

Background::~Background()
{
}

void Background::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}


