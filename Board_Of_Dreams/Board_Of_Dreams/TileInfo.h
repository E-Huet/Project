#pragma once
enum E_CellType {
	Ground = 0,
	Mountain,
	Water,
	Exit	
};

class TileInfo
{
	char symbol = ' ';
	bool traversable = false;
	bool swimmable = false;

public : 
	char GetSymbol(int value);
	bool IsTraversable(int value);
	bool IsSwimmable(int value);
};