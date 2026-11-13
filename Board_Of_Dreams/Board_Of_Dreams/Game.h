#pragma once
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "Map.h"

class Game
{
	int nbMap = 1;
	static Map currentMap;

	int GameLoop(Map map, Entity* player);
	void EndDelete();
	int ChangeMap();
	void Display(Map map);

public :
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	static Game* GetInstance();
	void Run();
};