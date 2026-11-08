#pragma once
#include "Ennemies.h"
class ZombieSwimmer :Ennemies
{
	protected:
		virtual ~ZombieSwimmer() = default;
	private:
		int damage = 1;
		int health = 1;
};

