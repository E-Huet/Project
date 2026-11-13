#include "Ennemies.h"
#include "Utilities.h"

bool Ennemies::CollidingEnemy(Coordinates coord) const
{
	return SetCoords(coord);
}

Ennemies* EnnemyAt(const EnnemyList& ennemies, Coordinates coords)
{
	for (const std::unique_ptr<Ennemies>& e : ennemies)
	{
		if (e->GetCoords() == coords)
		{
			return e.get();
		}
	}
	return nullptr;
}
void RemoveDead(EnnemyList& ennemies)
{
}
