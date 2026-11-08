#pragma once
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "Map.h"

class Game
{
	int map = 1;
	bool action = false;
	bool gameOver = false;
	bool end = false;
	bool spellMod = false;

	Map* currentMap = {};

	int GameLoop(Entity player);

	void EndDelete();
	int ChangeMap();

	void Display();

public :
	void GetInstance();
};