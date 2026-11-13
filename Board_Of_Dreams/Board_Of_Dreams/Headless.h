#pragma once
#include "Ennemies.h"
class Headless : public Ennemies
{
public:
	Headless(Coordinates startCoords)
		: Entity(startCoords, 'X', 1, 1),
		  Ennemies(startCoords, 'X', 1, 1)
	{
	}
	~Headless() override = default;

	void Act(const Entity& target, const Map& map, const EnnemyList& ennemies) override;
};

