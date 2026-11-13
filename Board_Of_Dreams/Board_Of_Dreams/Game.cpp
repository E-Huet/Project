#include "Game.h"
#include "LevelParser.h"
#include "Map.h"
#include "Entity.h"
#include "Warrior.h"
#include "Mage.h"
#include "Utilities.h"

#include <iostream>
#include <conio.h>

int Game::GameLoop(Map map, Entity* player)
{
    bool end = false;
    while (end == false)
    {
        bool spellMod = false;
        bool action = false;

        while (action == false)
        {
            char keyboard = _getch();
            if (map.Traversable(player->MoveEntity(keyboard, map.GetCoordsPlayer())) == true)
            {
                map.SetCoordsPlayer(player->MoveEntity(keyboard, map.GetCoordsPlayer()));
                action = true;
            }

            /// Bouger ennemis -> il me faut les fonctions d'Alex

        }
        /// Vérifs de fins et de PV
        action = false;
        system("cls");

        if (player->GetHealth() <= 0)
        {
            std::cout << "Game Over.";
            end = true;
        }
        else if (map.Exit(map.GetCoordsPlayer()))
        {
            ChangeMap();
            GetInstance();
        }
        else
        {
            Display(map);
        }
        return 0;
    }
}

void Game::EndDelete()
{
    return;
}

int Game::ChangeMap()
{
    nbMap ++;
    return nbMap;
}

void Game::Display(Map map)
{
    for (int i = 0; i < map.GetSizeMap().GetNbLines(); i++)
    {
        for (int j = 0; j < map.GetSizeMap().GetNbColumns(); j++)
        {
            if (map.GetCoordsPlayer().GetX() == j && map.GetCoordsPlayer().GetY() == i)
            {
                std::cout << 'H';
            }
            else
            {
                bool ennemi = false;
                Coordinates coords;
                coords.SetXY(j, i);
                if (map.InEnnemies(coords) != -1)
                {
                    std::cout << 'X';
                    ennemi = true;
                }
                if (map.GetMap()[i * map.GetSizeMap().GetNbColumns() + j] == 0 && ennemi == false)
                {
                    std::cout << '.';
                }
                else if (map.GetMap()[i * map.GetSizeMap().GetNbColumns() + j]== 1 && ennemi == false)
                {
                    std::cout << 'A';
                }
                else if (map.GetMap()[i * map.GetSizeMap().GetNbColumns() + j] == 2 && ennemi == false)
                {
                    std::cout << '~';
                }
                else if (map.GetMap()[i * map.GetSizeMap().GetNbColumns() + j] == 3 && ennemi == false)
                {
                    std::cout << 'E';
                }
                ennemi = false;
            }
        }
        std::cout << std::endl;
    }
}

Map Game::currentMap;

Game* Game::GetInstance()
{
    Map map;
    currentMap = map;
    LevelParser level;
    if (nbMap == 1)
    {
        level.GetFromFile(level.GetPathMap1(), currentMap);
    }
    else if (nbMap == 2)
    {
        level.GetFromFile(level.GetPathMap2(), currentMap);
    }
    else if (nbMap == 3)
    {
        level.GetFromFile(level.GetPathMap3(), currentMap);
    }
}

void Game::Run()
{
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

    GameLoop(currentMap, player);
    EndDelete();
}