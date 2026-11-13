#pragma once
#include "Utilities.h"
//Classe parente qui va être héritée par Player et Ennemies
class Entity
{
public:
    Entity(Coordinates startCoords = Coordinates(), char entitySymbol = '?', int startHealth = 1, int startDamage = 0);
	virtual ~Entity() = default;
	Coordinates GetCoords() const;
	char GetSymbol() const;
	int GetHealth() const;
	int GetDamage() const;
	void SetCoords(Coordinates coord);
	void SetHealth(int value);
	void SetDamage(int value);

	void ApplyDamage(int damageTaken);
	void Kill();
	bool IsAlive() const;
virtual bool CanSwim() const;
bool MoveEntity(char direction, const Map& map);
static bool DirectionTo(char direction, int& dx, int& dy);
	static bool IsDirectionKey(char c);
private:
	Coordinates coords;
	char symbol;
	int health;
	int damage;
bool CanEnter(Coordinates next, const Map& map) const;
};
