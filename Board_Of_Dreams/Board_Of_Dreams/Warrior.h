#pragma once
#include "Player.h"
class Warrior : public Player
{
public:
	Warrior(Coordinates startCoords) : Player(startCoords, 3, 2) {}
	~Warrior() override = default;

	std::string ClassName() const override { return "Guerrier"; }

	// Inflige ses dégâts à l'ennemi, et subit les dégâts de l'ennemi en recul.
	bool OnEnnemy(Ennemies& ennemy) override;
};
