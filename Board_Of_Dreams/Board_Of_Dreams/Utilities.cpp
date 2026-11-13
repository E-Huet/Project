#include "Utilities.h"

int Coordinates::TransformMap1D(SizeMap taille)
{
	return (y* taille.GetNbColumns() + x);
}

int Coordinates::GetX()
{
	return x;
}

int Coordinates::GetY()
{
	return y;
}

void Coordinates::SetXY(int valueX, int valueY)
{
	x = valueX;
	y = valueY;
}

int Coordinates::Add(int value, int valueToAdd)
{
	return value + valueToAdd;
}

int SizeMap::GetSize()
{
	return size;
}

int SizeMap::GetNbLines()
{
	return nbLines;
}

int SizeMap::GetNbColumns()
{
	return nbColumns;
}

int SizeMap::GetNbEnnemies()
{
	return nbEnnemies;
}

void SizeMap::SubstractEnnemy()
{
	nbEnnemies--;
}

void SizeMap::SetAll(int newSize, int newNbLines, int newNbColumns, int newNbEnnemies)
{
	size = newSize;
	nbLines = newNbLines;
	nbColumns = newNbColumns;
	nbEnnemies = newNbEnnemies;
}
