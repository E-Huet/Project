#pragma once
#include "Entity.h"
#include <vector>

class Ennemies : virtual public Entity
{
public:
	Ennemies(Coordinates startCoords, char entitySymbol, int startHealth, int startDamage)
		: Entity(startCoords, entitySymbol, startHealth, startDamage)
	{
	}
	~Ennemies() override = default;

	bool CollidingEnemy(Coordinates coord) const;

	// Tour de l'ennemi. 
	virtual void Move(const Entity& target, Coordinates coords) = 0;
};