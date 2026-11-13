#pragma once
#include "Player.h"
class Warrior : public Player
{
protected:
	virtual ~Warrior() = default;
private:
	int damage = 2;
	int health = 3;
	bool canUseSpell = false;
public:
	virtual void OnEnnemy() override;//inflige des dégats sur l'Ennemies
};