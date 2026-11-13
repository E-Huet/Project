#include "Mage.h"
#include <iostream>
bool Mage::SpellCast(EnnemyList& ennemies)
{
	return CastAreaSpell(*this, ennemies);
}

bool Mage::CastAreaSpell(const Entity& caster, EnnemyList& ennemies)
{
	bool hit = false;
	for (const std::unique_ptr<Ennemies>& e : ennemies)
	{
		int dx = std::abs(e->GetCoords().GetX() - caster.GetCoords().GetX());
		int dy = std::abs(e->GetCoords().GetY() - caster.GetCoords().GetY());
		if (dx <= spellRange && dy <= spellRange)
		{
			e->ApplyDamage(caster.GetDamage());
			hit = true;
		}
	}
	RemoveDead(ennemies);//j'arrive pas à trouver comment faire celle là
	return hit;
}
