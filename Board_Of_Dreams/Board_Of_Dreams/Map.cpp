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
	if (coords.GetX() > GetSizeMap().GetNbColumns() || coords.GetY() > GetSizeMap().GetNbLines() || coords.GetX() < 0 || coords.GetY() < 0)
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
	int temp = coords.TransformMap1D(size);
	if (map[temp] == 3)
	{
		return true;
	}
	return false;
}

Coordinates Map::GetCoordsPlayer()
{
	return coordsPlayer;
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
