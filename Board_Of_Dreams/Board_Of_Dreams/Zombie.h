#pragma once
#include "Ennemies.h"

class Zombie : public Ennemies
{
public:
	Zombie(Coordinates startCoords, char entitySymbol = 'Z')
		: Entity(startCoords, entitySymbol, 1, 1),
		  Ennemies(startCoords, entitySymbol, 1, 1)
	{
	}
	~Zombie() override = default;

	void Move(const Entity& target, Coordinates coords) override;

private:
	int turnCounter = 0;
};