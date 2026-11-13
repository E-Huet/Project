#pragma once
#include "Entity.h"
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
	virtual void Act(const Entity& target, const Map& map) = 0;
};

// Tous les ennemis du niveau 
using EnnemyList = std::vector<<Ennemies>;

Ennemies* EnnemyAt(const EnnemyList& ennemies, Coordinates coords); // nullptr si aucun
void RemoveDead(EnnemyList& ennemies);

};
