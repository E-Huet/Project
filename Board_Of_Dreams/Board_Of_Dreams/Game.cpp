#include "Game.h"
#include "LevelParser.h"
#include "Map.h"
#include "Entity.h"
#include "Warrior.h"
#include "Mage.h"

#include <iostream>
#include <conio.h>


int Game::GameLoop(Entity player)
{
    bool action = false;
    while (action == false)
    {
        char key = _getch();
        player.MoveEntity(key, player.);

    }
    
    system("cls");
    return 0;
}

void Game::EndDelete()
{
    return;
}

int Game::ChangeMap()
{
    map ++;
    return map;
}

void Game::Display()
{
    //for (int i = 0; i < nb_lines; i++)
//{
//	for (int j = 0; j < nb_columns; j++)
//	{
//		if (player.GetCoordX() == j && player.GetCoordY() == i)
//		{
//			std::cout << 'H';
//		}
//		
//}
    return;
}

void Game::GetInstance()
{
    Map currentMap;
    LevelParser level;
    level.GetFromFile(level.GetPathMap1(), currentMap);


    Warrior warrior;
    Mage mage;
    Entity* player;
    std::cout << "1 : Warrior | 2 : Mage\n--> ";
    int choice = 0;
    while (true)
    {
        std::cin >> choice;
        if (choice == 1)
        {
             player = &warrior;
        }
        else if (choice == 2)
        {
            player = &mage;
        }
        std::cout << "Number not recognized, try again.\n--> ";
    }

    bool end = false;
    while (end == false)
    {
        GameLoop(player);
    }
}