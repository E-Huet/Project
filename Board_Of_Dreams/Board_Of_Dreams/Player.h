#pragma once
#include "Entity.h"
#include "Utilities.h"
#include <conio.h>
class Player : public Entity
{
protected:
	virtual ~Player() = default;
public:
	virtual bool CollidingEnemy(Coordinates coord) override;
	char ReadPlayerInput();
	Coordinates GetDirection(Coordinates player);
	virtual void OnEnnemy() = 0;

private:
	char keyboard = 'a';
	Coordinates player = { 0,0 };
};