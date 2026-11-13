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
	char GetSymbol();
	bool IsTraversable();
	bool IsSwimmable();

	void SetAll(char character, bool boolTraversable, bool boolSwimmable);
};