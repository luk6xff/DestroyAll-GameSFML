#pragma once
// Entity category, used to dispatch commands
namespace Category
{
	enum Type
	{
		None = 0,
		Scene = 1 << 0,
		PlayerTank = 1 << 1,
		EnemyTank = 1 << 2,
	};
}
