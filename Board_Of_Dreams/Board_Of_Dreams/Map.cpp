#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Ennemies.h"


std::vector<int> Map::GetMap()
{
	return map;
}

int Map::GetSize()
{
	return size;
}

int Map::GetNbLines()
{
	return nb_lines;
}

int Map::GetNbColumns()
{
	return nb_columns;
}

int Map::GetNbEnnemies()
{
	return nb_ennemies;
}

void Map::SetMap(std::vector<int> vector)
{
	map = vector;
}

void Map::SetSize(int value)
{
	if (value < 0)
	{
		value = 0;
	}
	size = value;
}

void Map::SetNbLines(int value)
{
	if (value < 0)
	{
		value = 0;
	}
	nb_lines = value;
}

void Map::SetNbColumns(int value)
{
	if (value < 0)
	{
		value = 0;
	}
	nb_columns = value;
}

void Map::SetNbEnnemies(int value)
{
	if (value < 0)
	{
		value = 0;
	}
	nb_ennemies = value;
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
	return false;
}

bool Map::Exit(Coordinates coords)
{
	return false;
}

