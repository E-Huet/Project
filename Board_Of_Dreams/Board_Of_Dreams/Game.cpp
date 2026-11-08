#include "Game.h"
#include "LevelParser.h"
#include "Map.h"
#include "Entity.h"
#include "Warrior.h"
#include "Mage.h"

#include <iostream>
#include <conio.h>


int Game::GameLoop()
{
    bool action = false;
    while (action == false)
    {
        char touche = _getch();


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

void Game::GetInstance()
{
    Map currentMap;
    LevelParser level;
    level.GetFromFile(level.GetPathMap1(), currentMap);


    Warrior warrior;

    std::cout << "1 : Warrior | 2 : Mage\n--> ";
    int choice = 0;
    while (true)
    {
        std::cin >> choice;
        if (choice == 1)
        {
            Entity* player = &warrior;
        }
        else if (choice == 2)
        {
            break;
        }
        std::cout << "Number not recognized, try again.\n--> ";
    }

    bool end = false;

    while (end == false)
    {
        GameLoop();
    }
}