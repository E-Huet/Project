#include "Ennemies.h"
#include "Utilities.h"

bool Ennemies::CollidingEnemy(Coordinates coord)
{
	if (creatures_x == coord.GetX() && creatures_y == coord.GetY())
	{
		return true;
	}
	return false;
}
