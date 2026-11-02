#pragma once

static struct Coordinates
{
private :
	int x = 0;
	int y = 0;
public :
	int TransformMap1D(TailleMap taille);
	int GetX();
	int GetY();

	void SetXY(int valueX, int valueY);

	int Add(int value, int valueToAdd);
	bool CompareEqualityCoords(Coordinates coord, Coordinates coord2);
};

class TailleMap
{
private:
	int size = 0;
	int nbLines = 0;
	int nbColumns = 0;
	int nbEnnemies = 0;

public:
	int GetSize();
	int GetNbLines();
	int GetNbColumns();
	int GetNbEnnemies();

	void SetSize(int value);
	void SetNbLines(int value);
	void SetNbColumns(int value);
	void SetNbEnnemies(int value);
};