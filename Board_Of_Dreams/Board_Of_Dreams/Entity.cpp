#include <iostream>
#include "Entity.h"
#include "Map.h"


bool Entity::CanMove(int new_x, int new_y)
{
	if (&Map::CheckLimits)
	{
		if (TileInfo::IsTraversable)
		{
			return true;
		}
	}
	return false;
}

Coordinates Entity::MoveEntity(char keyboard, Coordinates direction)
{
	int directionx = 0; 
	int directiony = 0;

	switch (keyboard)
	{
	case 'z':
		directionx = -1;
		break;
	case 's':
		directionx = 1;
		break;
	case 'q':
		directiony = -1;
		break;
	case 'd':
		directiony = 1;
		break;
	default:
		return { direction.x,direction.y };
	}
	int new_x = direction.x + directionx;  int new_y = direction.y + directiony;
	if (Entity::CanMove)
	{
		direction.x = new_x; direction.y = new_y;
		return { direction.x,direction.y };
	}
	return { -1,-1 };
}

void Entity::ApplyDamage(int damageTaken)
{
	health -= damageTaken;
}
bool Entity::IsAlive()
{
	return health>0;
}
int Entity::GetDamage()
{
	return damage;
}
int Entity::GetHealth()
{
	return health;
}
void Entity::SetDamage(int value)
{
	damage = value;
}
void Entity::SetHealth(int value)
{
	health = value;
}

void Entity::SetCoords(Coordinates coord)
{
	int x = coord.x;
	int y = coord.y;
}
