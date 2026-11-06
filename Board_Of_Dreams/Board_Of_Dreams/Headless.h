#pragma once
#include "Ennemies.h"
class Headless:Ennemies
{
protected:
	virtual ~Headless() = default;
private:
	int damage = 1;
	int health = 1;
};

