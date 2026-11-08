#include <iostream>
#include "Game.h"
#include "Map.h"
int main()
{
    Game* game = {};
    game->GameLoop();
    // on oublie pas de delete dans le destructeur
    return 0;
}
