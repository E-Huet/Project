#include "Headless.h"
#include <cstdlib>

void Headless::Move(const Entity& target, Coordinates coords)
{
	static const char directions[4] = { 'z', 's', 'q', 'd' };
	MoveEntity(directions[std::rand() % 4], coords);
}