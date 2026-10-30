#pragma once
#include "Ennemies.h"
class Headless:Ennemies
{
protected:
	virtual ~Headless() = default;
private:
	Coordinates coords = { 0,0 };
	int damage = 1;
	int health = 1;
public:
	void MoveEntity();
};

