#pragma once
#include "Ennemies.h"
class ZombieSwimmer :Ennemies
{
	protected:
		virtual ~ZombieSwimmer() = default;
	private:
		Coordinates coords = { 0,0 };
		int damage = 1;
		int health = 1;
	public:
		void MoveEntity();
};

