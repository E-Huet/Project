#pragma once
#include "Entity.h"
class Ennemies :Entity
{
protected:
	virtual ~Ennemies() = default;
public:
	virtual bool CollidingEnemy(Coordinates coord) override;
private:
	int creatures_x = 0;
	int creatures_y = 0;

};