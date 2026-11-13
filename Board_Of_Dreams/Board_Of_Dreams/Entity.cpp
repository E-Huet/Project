#include <iostream>
#include "Entity.h"
#include "TileInfo.h"

Entity::Entity(Coordinates startCoords, char entitySymbol, int startHealth, int startDamage)
	: coords(startCoords), symbol(entitySymbol), health(startHealth), damage(startDamage)
{
}
int Entity::GetDamage() const
{
	return damage;
}
int Entity::GetHealth() const
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
	coords = coord;
}
void Entity::ApplyDamage(int damageTaken)
{
	SetHealth(health -= damageTaken);
}
void Entity::Kill()
{
	health = 0;
}

bool Entity::IsAlive() const
{
	return health > 0;
}

bool Entity::CanSwim() const
{
	return false;
}

bool Entity::DirectionTo(char direction, int& dx, int& dy)
{
	dx = 0;
	dy = 0;
	switch (direction)
	{
	case 'z':
		dy = -1;
		return true;
	case 's':
		dy = 1;
		return true;
	case 'q':
		dx = -1;
		return true;
	case 'd':
		dx = 1;
		return true;
	default:
		return false;
	}
}

bool Entity::IsDirectionKey(char c)
{
	int dx = 0;
	int dy = 0;
	return DirectionTo(c, dx, dy);
}

bool Entity::MoveEntity(char direction, const Map& map, const BlockedFn& isBlocked)
{
	int dx = 0;
	int dy = 0;
	if (!DirectionToDelta(direction, dx, dy))
	{
		return false;
	}
	Coordinates next(coords.GetX() + dx, coords.GetY() + dy);
	if (!CanEnter(next, map))//C'est la fonction qui verifie si tu peux te deplacer que tu veux faire dans Map
	{
		return false;
	}
	coords = next;
	return true;
}
