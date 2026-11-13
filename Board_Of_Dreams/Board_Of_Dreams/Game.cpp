#include "Game.h"
#include "LevelParser.h"
#include "Map.h"
#include "Entity.h"
#include "Warrior.h"
#include "Mage.h"
#include "Utilities.h"

#include <iostream>
#include <conio.h>

int Game::GameLoop(Entity* player)
{
    bool end = false;
    while (end == false)
    {
        bool action = false;

        while (action == false)
        {
            char keyboard = _getch();
            if (keyboard == 'p')
            {

            }
            else
            {
                Coordinates newCoords = player->MoveEntity(keyboard, currentMap.GetCoordsPlayer());
                if (currentMap.Traversable(newCoords))
                {
                    currentMap.SetCoordsPlayer(newCoords.GetX(), newCoords.GetY());
                    action = true;
                }
            }
        }
        /// Bouger ennemis -> il me faut les fonctions d'Alex

        /// Vérifs de fins et de PV
        action = false;
        system("cls");

        if (player->GetHealth() <= 0)
        {
            std::cout << "Game Over.";
            end = true;
        }
        else if (currentMap.Exit(currentMap.GetCoordsPlayer()))
        {
            ChangeMap();
            InitializeMap();
        }
        else
        {
            Display();
        }
        
    }
    return 0;
}

int Game::ChangeMap()
{
    nbMap ++;
    return nbMap;
}

void Game::InitializeMap()
{
    LevelParser level;
    if (nbMap == 1)
        level.GetFromFile(level.GetPathMap1(), currentMap);
    else if (nbMap == 2)
        level.GetFromFile(level.GetPathMap2(), currentMap);
    else if (nbMap == 3)
        level.GetFromFile(level.GetPathMap3(), currentMap);
}

void Game::Display()
{
    for (int i = 0; i < currentMap.GetSizeMap().GetNbLines(); i++)
    {
        for (int j = 0; j < currentMap.GetSizeMap().GetNbColumns(); j++)
        {
            if (currentMap.GetCoordsPlayer().GetX() == j && currentMap.GetCoordsPlayer().GetY() == i)
            {
                std::cout << 'H';
            }
            else
            {
                bool ennemi = false;
                Coordinates coords;
                coords.SetXY(j, i);
                if (currentMap.InEnnemies(coords) != -1)
                {
                    std::cout << 'X';
                    ennemi = true;
                }
                if (currentMap.GetMap()[i * currentMap.GetSizeMap().GetNbColumns() + j] == 0 && ennemi == false)
                {
                    std::cout << '.';
                }
                else if (currentMap.GetMap()[i * currentMap.GetSizeMap().GetNbColumns() + j] == 1 && ennemi == false)
                {
                    std::cout << 'M';
                }
                else if (currentMap.GetMap()[i * currentMap.GetSizeMap().GetNbColumns() + j] == 2 && ennemi == false)
                {
                    std::cout << '~';
                }
                else if (currentMap.GetMap()[i * currentMap.GetSizeMap().GetNbColumns() + j] == 3 && ennemi == false)
                {
                    std::cout << 'E';
                }
                ennemi = false;
            }
        }
        std::cout << std::endl;
    }
}

void Game::Spell()
{
    Coordinates coordsEnnemy = currentMap.GetCoordsPlayer();
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            coordsEnnemy.SetXY(currentMap.GetCoordsPlayer().GetX() + i, currentMap.GetCoordsPlayer().GetY() + j);
            if (currentMap.InEnnemies(coordsEnnemy) != -1)
            {
                currentMap.RemoveEnemy(coordsEnnemy);
            }
        }
    }
}

Game* Game::GetInstance()
{
    object = new Game();
    return object;
}

void Game::Run()
{
    Map map;
    currentMap = map;
    InitializeMap();

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
            break;
        }
        else if (choice == 2)
        {
            player = &mage;
            break;
        }
        std::cout << "Number not recognized, try again.\n--> ";
    }
    system("cls");
    GameLoop(player);
}