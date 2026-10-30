#pragma once
#include <conio.h>
#include <cstdlib>
#include <ctime>

class Game
{
	int map = 1;
	bool action = false;
	bool gameOver = false;
	bool end = false;
	bool spellMod = false;

public :
	void PlayerEvents();
	void EnnemiesEvents(); // 
	int GameLoop();  // boucle while : appelle playerEvents 
					 // puis EnnemiesEvents, puis clear le code
					 // et fait les vérifs(?) 
					 // à la fin boucle : appelle EndDelete()
	void EndDelete();
	int ChangeMap();
};