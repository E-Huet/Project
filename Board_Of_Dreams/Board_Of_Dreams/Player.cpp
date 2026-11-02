#include "Player.h"

bool Player::CollidingEnemy(Coordinates coord)
{
	return true;
}

char Player::ReadPlayerInput()
{
	keyboard = _getch();
	return keyboard;
}

Coordinates Player::GetDirection(Coordinates player)
{
	keyboard = ReadPlayerInput();
	return Entity::MoveEntity(keyboard, player);
}
