#pragma once
#include "Player.h"
class Mage : public Player
{
public:
	Mage(Coordinates startCoords) : Player(startCoords, 2, 1) {}
	~Mage() override = default;

	std::string ClassName() const override { return "Mage"; }

	bool CanUseSpell() const override { return true; }
};