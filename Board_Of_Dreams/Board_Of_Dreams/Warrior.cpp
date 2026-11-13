#include "Warrior.h"
  bool Warrior::OnEnnemy(Ennemies& ennemy)
{
	ennemy.ApplyDamage(GetDamage());      // le guerrier blesse l'ennemi (2 dégâts)
	ApplyDamage(ennemy.GetDamage());      // recul : il subit les dégâts de l'ennemi
	return true;                          // contact géré : pas de dégâts supplémentaires
}
