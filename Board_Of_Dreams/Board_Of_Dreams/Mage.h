#pragma once
#include "Player.h"
class Mage : public Player
{
public:
	static constexpr int spellRange = 1;   // 1 = les 8 cases autour du lanceur

	Mage(Coordinates startCoords) : Player(startCoords, 2, 1) {}
	~Mage() override = default;

	std::string ClassName() const override { return "Mage"; }

	bool CanUseSpell() const override { return true; }
	bool SpellCast(EnnemyList& ennemies) override;

	static bool CastAreaSpell(const Entity& caster, EnnemyList& ennemies);
};
