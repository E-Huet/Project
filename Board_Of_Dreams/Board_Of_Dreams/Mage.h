#pragma once
#include "Player.h"
class Mage : Player
{
protected:
	virtual ~Mage() = default;
private :
	Coordinates coords = {0,0};
	int damage = 1;
	int health = 1;
public:
	void SpellCast();
	void MoveEntity();
};

