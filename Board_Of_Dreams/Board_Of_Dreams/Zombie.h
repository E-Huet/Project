#pragma once
#include "Ennemies.h"
class Zombie:Ennemies
{
protected:
	virtual ~Zombie() = default;
private:
	int damage = 1;
	int health = 1;
};

