#pragma once
#include "Entity.h"
class Ennemies:Entity
{
protected:
	virtual ~Ennemies() = default;
public:
	virtual bool CollidingEnemy() override;
	virtual void MoveEntity() = 0;
	virtual void TakeDamage() override;
	//Getter
	virtual Coordinates GetCoords() override;
	virtual int GetDamage() override;
	virtual int GetHealth() override;
	//Setter
	virtual void SetCoords() override;
	virtual void SetDamage() override;
	virtual void SetHealth() override;
};

