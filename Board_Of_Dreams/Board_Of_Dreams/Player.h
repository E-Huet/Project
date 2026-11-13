#pragma once
#include <string>
#include "Entity.h"
#include "Enemy.h"

class Map;
class Player : public Entity
{
public:
	Player(int x, int y, int health);
	~Player() override = default;
	virtual std::string className() const = 0;
	virtual bool onEnemyContact(Enemy& enemy) 
{ return false; }

	virtual bool hasSpell() const
{
	return false;
}
	virtual bool castSpell(EnemyList& enemy)
{ return false; }
};
