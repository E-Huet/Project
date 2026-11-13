include "Zombie.h"
#include <cstdlib>
#include <vector>
namespace
{
	std::vector<char> BuildOrder(int dx, int dy)
	{
		std::vector<char> vertical;
		std::vector<char> horizontal;
		if (dy != 0)
		{
			vertical.push_back((dy < 0) ? 'z' : 's');
		}
		if (dx != 0)
		{
			horizontal.push_back((dx < 0) ? 'q' : 'd');
		}
		if (std::abs(dy) >= std::abs(dx))
		{
			vertical.insert(vertical.end(), horizontal.begin(), horizontal.end());
			return vertical;
		}
		horizontal.insert(horizontal.end(), vertical.begin(), vertical.end());
		return horizontal;
	}

void Zombie::Act(const Entity& target, const Map& map)
{
	int dx = target.GetCoords().GetX() - GetCoords().GetX();
	int dy = target.GetCoords().GetY() - GetCoords().GetY();
	for (char direction : BuildOrder(dx, dy))
	{
		if (MoveEntity(direction, map))
		{
			return;
		}
	}
}
