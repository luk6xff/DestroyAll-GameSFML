#pragma once

namespace sf
{
	class Texture;
}


namespace Textures
{
	enum ID
	{
		PlayerTank,
		EnemyTank,
		BackgorundTexture
	};
}

//forward declaration:
template<typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;