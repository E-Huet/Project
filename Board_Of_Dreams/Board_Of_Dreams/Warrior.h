#pragma once
#include "Player.h"
class Warrior : public Player
{
	~Warrior() = default;
	int damage = 2;
	int health = 3;
	bool canUseSpell = false;
public:
	virtual void OnEnnemy() override;//inflige des dégats sur l'Ennemies
};
