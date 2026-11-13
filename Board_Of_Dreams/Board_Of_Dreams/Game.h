#pragma once
#include "Map.h"
#include "Entity.h"

class Game
{
	int nbMap = 1;
	Map currentMap;

	int GameLoop(Player* player);
	int ChangeMap();
	void InitializeMap();
	void Display();
	void Spell();

	static Game* object;

	Game() = default;

public :
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	static Game* GetInstance();
	void Run();
};