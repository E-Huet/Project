#include "Player.h"

Player::Player(Coordinates startCoords, int health, int damage)
    : Entity(startCoords, 'H', health, damage)
{
}
