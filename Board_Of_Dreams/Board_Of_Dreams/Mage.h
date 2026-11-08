#pragma once
#include "Player.h"
class Mage : public Player
{
protected:
	virtual ~Mage() = default;
private :
	Coordinates coords = {0,0};
	int damage = 1;
	int health = 1;
	bool canUseSpell = true;
public:
	void SpellCast();
	virtual void OnEnnemy() override;
};

