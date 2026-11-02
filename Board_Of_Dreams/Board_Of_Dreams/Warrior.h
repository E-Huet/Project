#pragma once
#include "Player.h"
class Warrior : Player
{
protected:
	virtual ~Warrior() = default;
private:
	Coordinates coords = { 0,0 };
	int damage = 2;
	int health = 3;
	bool canUseSpell = false;
public:
	virtual void OnEnnemy() override;
};

