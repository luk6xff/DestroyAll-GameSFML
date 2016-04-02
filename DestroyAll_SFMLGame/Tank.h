#pragma once
#include "Entity.h"
#include "ResourceIdentifiers.h"

class Tank : public Entity
{

public:
	enum Type
	{
		Player,
		Enemy
	};

public:
	explicit Tank(Type type,const TextureHolder& textures);
	virtual void drawCurrent(sf::RenderTarget& target,sf::RenderStates states) const;
	~Tank();

private:
	Type mType;
	sf::Sprite mSprite;

};

