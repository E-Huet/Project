#pragma once
#include "Player.h"
class Mage : Player
{
protected:
	virtual ~Mage() = default;
private :
	int damage = 1;
	int health = 1;
	bool canUseSpell = true;
public:
	void SpellCast();//Le sort
	virtual void OnEnnemy() override;//se prend juste des dégats
};

