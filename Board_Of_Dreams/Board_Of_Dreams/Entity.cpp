#include <iostream>
#include "Entity.h"
#include "TileInfo.h"

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

void Entity::ApplyDamage(int damageTaken)
{
	SetHealth(health -= damageTaken);
}
bool Entity::IsAlive()
{
	return health>0;
}

void Entity::SetCoords(Coordinates coord)
{
	int x = coord.x;
	int y = coord.y;
}
