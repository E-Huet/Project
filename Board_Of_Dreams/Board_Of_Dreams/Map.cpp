#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Ennemies.h"
#include <random>
#include <time.h>
#include "Utilities.h"


SizeMap Map::GetSizeMap()
{
	return size;
}

std::vector<int> Map::GetMap()
{
	return map;
}

bool Map::InLimitsMap(Coordinates coords)
{
	if (coords.GetX() >= GetSizeMap().GetNbColumns() || coords.GetY() >= GetSizeMap().GetNbLines() || coords.GetX() < 0 || coords.GetY() < 0)
	{
		return false;
	}
	return true;
}

void Map::AddToMap(int value)
{
	map.push_back(value);
}

void Map::AddToEnnemies(Coordinates coords)
{
	ennemies.push_back(coords);
}

void Map::AddToTiles(TileInfo tileinfo)
{
	tiles.push_back(tileinfo);
}

void Map::SetCoordsPlayer(int x, int y)
{
	coordsPlayer.SetXY(x, y);
}

void Map::SetSizeMap(int newSize, int lines, int columns, int enemies)
{
	size.SetAll(newSize, lines, columns, enemies);
}

void Map::Clear()
{
	map.clear();
	ennemies.clear();
	tiles.clear();
	coordsPlayer.SetXY(0, 0);
	size.SetAll(0, 0, 0, 0);
}

void Map::RemoveEnemy(Coordinates coordsEnnemies)
{
	int index = InEnnemies(coordsEnnemies);
	if (index != -1)
	{
		ennemies.erase(ennemies.begin() + index);
	}
	size.SubstractEnnemy();
}

bool Map::Traversable(Coordinates coords)
{
	if (InLimitsMap(coords))
	{
		int nb = coords.TransformMap1D(size);
		return tiles[nb].IsTraversable();
	}
	return false;
}

bool Map::Swimmable(Coordinates coords)
{
	if (InLimitsMap(coords))
	{
		int temp = coords.TransformMap1D(size);
		return tiles[temp].IsSwimmable();
	}
	return false;
}

bool Map::Exit(Coordinates coords)
{
	if (InLimitsMap(coords))
	{
		int temp = coords.TransformMap1D(size);
		if (map[temp] == 3)
		{
			return true;
		}
	}
	return false;
}

Coordinates Map::GetCoordsPlayer()
{
	return coordsPlayer;
}

Coordinates Map::GetEnnemy(int index)
{
	if (index >= 0 && index < GetSizeMap().GetNbEnnemies())
	{
		return ennemies[index];
	}
}

int Map::InEnnemies(Coordinates coords)
{
	for (int i = 0; i < GetSizeMap().GetNbEnnemies(); i++)
	{
		if (ennemies[i].GetX() == coords.GetX() && ennemies[i].GetY() == coords.GetY())
		{
			return i;
		}
	}
	return -1;
}
