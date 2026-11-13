#include "Player.h"

Player::Player(int x, int y, int health)
	: Entity(x, y, config::player_char, health)
{
}
