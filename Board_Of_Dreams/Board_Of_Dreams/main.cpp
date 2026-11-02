#include <iostream>
#include "Game.h"

int main()
{
    Game* game = Game::GetInstance();
    game->GameLoop();
    // on oublie pas de delete dans le destructeur
    return 0;
}
