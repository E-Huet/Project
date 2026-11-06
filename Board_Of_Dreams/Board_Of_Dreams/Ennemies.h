#pragma once
#include "Entity.h"
class Ennemies :Entity
{
protected:
	virtual ~Ennemies() = default;//le destructeur
public:
	virtual bool CollidingEnemy(Coordinates coord) override;
	virtual void MoveEntity(char keyboard, Coordinates coord)=0;//les déplacements sont différents entre Headless et Zombies
private:
	int creatures_x = 0;
	int creatures_y = 0;

};