#include "Ennemies.h"

bool Ennemies::CollidingEnemy(Coordinates coord)
{
	if (creatures_x == coord.x && creatures_y == coord.y)
	{
		return true;
	}
	return false;
}
