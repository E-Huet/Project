#pragma once
#include "Utilities.h"
//Classe parente qui va être héritée par Player et Ennemies
class Entity
{
public:
    Entity(Coordinates startCoords = Coordinates(), char entitySymbol = '?', int startHealth = 1, int startDamage = 0);
	virtual ~Entity() = default;
	Coordinates GetCoords() const;
	int GetHealth() const;
	int GetDamage() const;

	void SetCoords(Coordinates coord);
	void SetHealth(int value);
	void SetDamage(int value);

	void ApplyDamage(int damageTaken);
	void Kill();
	bool IsAlive() const;
	virtual bool CanSwim() const;
	Coordinates MoveEntity(char direction, Coordinates coordsEntity);
	static bool DirectionTo(char direction, int& dx, int& dy);
private:
	Coordinates coords;
	int health;
	int damage;
};
