#include "Mage.h"
#include <iostream>
void Mage::SpellCast()
{
	if (canUseSpell)
	{
		std::cout << "Spell Used";
	}
}

void Mage::OnEnnemy()
{
}

