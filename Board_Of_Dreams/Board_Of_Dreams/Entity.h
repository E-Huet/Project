#pragma once
#include "Utilities.h"
class Entity
{
protected:
	virtual ~Entity() = default;
public:
	virtual bool CollidingEnemy() = 0;
	virtual void MoveEntity() = 0;
	virtual void TakeDamage() = 0;
	//Getter
	virtual Coordinates GetCoords() = 0;
	virtual int GetDamage() = 0;
	virtual int GetHealth() = 0;
	//Setter
	virtual void SetCoords() = 0;
	virtual void SetDamage() = 0;
	virtual void SetHealth() = 0;
};

