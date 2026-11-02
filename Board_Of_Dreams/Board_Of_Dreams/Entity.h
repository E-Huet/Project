#pragma once
#include "Utilities.h"
class Entity
{
protected:
	virtual ~Entity() = default;
public:
	virtual bool CollidingEnemy(Coordinates coord) = 0;
	virtual void OnEnnemy() = 0;
	virtual void TakeDamage() = 0;
	bool CanMove(int new_x, int new_y);
	Coordinates MoveEntity(char keyboard, Coordinates direction);
	void ApplyDamage(int damageTaken);
	bool IsAlive();
	//Getter
	int GetDamage();
	int GetHealth();
	//Setter
	void SetDamage(int value);
	void SetHealth(int value);
	void SetCoords(Coordinates coord);
private:
	int health = 1;
	int damage = 1;
};

