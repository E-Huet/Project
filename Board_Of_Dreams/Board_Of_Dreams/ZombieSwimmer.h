#pragma once
class ZombieSwimmer : public Zombie, public Swimmer
{
public:
	ZombieSwimmer(Coordinates startCoords)
		: Entity(startCoords, 'S', 1, 1),
		  Zombie(startCoords, 'S'),
		  Swimmer()
	{
	}
	~ZombieSwimmer() override = default;
};

