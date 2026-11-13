#pragma once
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "Map.h"
#include "Entity.h"

class Game
{
	int nbMap = 1;
	Map currentMap;

	int GameLoop(Entity* player);
	void EndDelete();
	int ChangeMap();
	void InitializeMap();
	void Display(Map map);

	static Game* object;

	Game() = default;

public :
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	static Game* GetInstance();
	void Run();
};