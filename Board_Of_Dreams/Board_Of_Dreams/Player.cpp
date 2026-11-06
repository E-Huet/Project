#include "Player.h"
#include "Utilities.h"
bool Player::CollidingEnemy(Coordinates coord)
{
	return true;
}

char Player::ReadPlayerInput()
{
	keyboard = _getch();
	return keyboard;
}

void Player::MoveEntity(char keyboard, Coordinates direction)
{
	int directionx = 0;
	int directiony = 0;

	switch (keyboard)
	{
	case 'z':directionx = -1;	break;	case 's':directionx = 1;	break;
	case 'q':directiony = -1;	break;	case 'd':directiony = 1;	break;
	default:return;
	}
	int new_x = direction.GetX() + directionx;  
	int new_y = direction.GetY() + directiony;
	if (Entity::CanMove(new_x,new_y))
	{
		direction.SetXY(new_x, new_y);
	}
}