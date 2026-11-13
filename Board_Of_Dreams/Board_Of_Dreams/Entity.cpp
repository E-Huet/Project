#include <iostream>
#include "Entity.h"
#include "TileInfo.h"

Entity::Entity(Coordinates startCoords, char entitySymbol, int startHealth, int startDamage)
	: coords(startCoords), health(startHealth), damage(startDamage)
{
}
Coordinates Entity::GetCoords() const
{
	return coords;
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

Coordinates Entity::MoveEntity(char direction, Coordinates coordsEntity)
{
	int dx = 0;
	int dy = 0;
	DirectionTo(direction, dx, dy);

	coordsEntity.SetXY(coordsEntity.GetX() + dx, coordsEntity.GetY() + dy);
	return coordsEntity;
}
