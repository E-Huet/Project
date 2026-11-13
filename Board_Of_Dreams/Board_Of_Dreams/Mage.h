#pragma once
#include "Player.h"
class Mage : public Player
{
	~Mage() = default;
	int damage = 1;
	int health = 1;
	bool canUseSpell = true;
public:
	void SpellCast();//Le sort
	virtual void OnEnnemy() override;//se prend juste des dégats
};

