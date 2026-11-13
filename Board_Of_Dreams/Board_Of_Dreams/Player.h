#pragma once
#include <string>
#include "Entity.h"
#include "Ennemies.h"

class Map;
class Player : public Entity
{
public:
	Player(Coordinates startCoords, int health, int damage);
	~Player() override = default;
	virtual std::string ClassName() const = 0;
	virtual bool OnEnemyContact(Ennemies& enemy) 
{ return false; }

	virtual bool CanUseSpell() const
{
	return false;
}
{ return false; }
};
