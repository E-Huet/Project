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

void Map::AddToTiles(TileInfo tileinfo)
{
	tiles.push_back(tileinfo);
}

bool Map::CheckLimits()
{
	return false;
}

bool Map::Traversable(Coordinates coords)
{
	int temp = coords.TransformMap1D(size);
	return tiles[temp].IsTraversable();
}

bool Map::Swimmable(Coordinates coords)
{
	int temp = coords.TransformMap1D(size);
	return tiles[temp].IsSwimmable();
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
