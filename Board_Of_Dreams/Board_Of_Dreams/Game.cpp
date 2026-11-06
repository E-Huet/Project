#include "Game.h"
#include "LevelParser.h"
#include "Map.h"

void Game::PlayerEvents()
{
}

int Game::GameLoop()
{
    PlayerEvents();
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

    GameLoop();
}