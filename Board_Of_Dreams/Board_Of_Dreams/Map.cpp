#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Ennemies.h"
#include <random>
#include <time.h>
#include "Utilities.h"


TailleMap Map::GetSizeMap()
{
	return size;
}

std::vector<int> Map::GetMap()
{
	return map;
}

void Map::AddToMap(int value)
{
	map.push_back(value);
}

void Map::AddToEnnemies(Coordinates coords)
{
	return;
}

void Map::DisplayMap()
{
	//for (int i = 0; i < nb_lines; i++)
	//{
	//	for (int j = 0; j < nb_columns; j++)
	//	{
	//		if (player.GetCoordX() == j && player.GetCoordY() == i)
	//		{
	//			std::cout << 'H';
	//		}
	//		
	//}
}

bool Map::CheckLimits()
{
	return false;
}

bool Map::Traversable(Coordinates coords)
{
	int temp = coords.TransformMap1D(size);
	if (map[temp] == 0 || map[temp] == 3)
	{
		return true;
	}
	return false;
}

bool Map::Exit(Coordinates coords)
{
	int temp = coords.TransformMap1D(size);
	if (map[temp] == 3)
	{
		return true;
	}
	return false;
}
