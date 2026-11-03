#include "Utilities.h"

int Coordinates::TransformMap1D(TailleMap taille)
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

int TailleMap::GetSize()
{
	return size;
}

int TailleMap::GetNbLines()
{
	return nbLines;
}

int TailleMap::GetNbColumns()
{
	return nbColumns;
}

int TailleMap::GetNbEnnemies()
{
	return nbEnnemies;
}

void TailleMap::SetSize(int value)
{
	size = value;
}

void TailleMap::SetNbLines(int value)
{
	nbLines = value;
}

void TailleMap::SetNbColumns(int value)
{
	nbColumns = value;
}

void TailleMap::SetNbEnnemies(int value)
{
	nbEnnemies = value;
}
