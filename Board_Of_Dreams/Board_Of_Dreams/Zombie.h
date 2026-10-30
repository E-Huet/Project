#pragma once
#include "Ennemies.h"
class Zombie:Ennemies
{
protected:
	virtual ~Zombie() = default;
private:
	Coordinates coords = { 0,0 };
	int damage = 1;
	int health = 1;
public:
	void MoveEntity();
};

