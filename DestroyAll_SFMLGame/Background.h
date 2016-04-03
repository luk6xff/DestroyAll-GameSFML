#pragma once
#include "Entity.h"
#include "ResourceIdentifiers.h"

class Background:public Entity
{
public:
	explicit Background(const sf::Texture& texture);
	Background(const sf::Texture& texture,const sf::IntRect& rect);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	~Background();


private:
	sf::Sprite mSprite;
};
