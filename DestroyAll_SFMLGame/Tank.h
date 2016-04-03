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
	virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
	virtual unsigned int	getCategory() const;
	~Tank();

private:
	Type mType;
	sf::Sprite mSprite;

};

