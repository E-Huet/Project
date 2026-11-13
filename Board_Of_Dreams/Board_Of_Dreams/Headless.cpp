#include "Headless.h"
#include <cstdlib>

void Headless::Act(const Entity&, const Map& map, const EnnemyList& ennemies)
{
	static const char directions[4] = { 'z', 's', 'q', 'd' };
	MoveEntity(directions[std::rand() % 4], map, &ennemies);
}
