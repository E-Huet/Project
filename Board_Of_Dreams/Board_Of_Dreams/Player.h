#pragma once
#include "Entity.h"
#include "Utilities.h"
#include <conio.h>
class Player : public Entity
{
protected:
	virtual ~Player() = default; //détruit la classe à la fin 
public:
	virtual bool CollidingEnemy(Coordinates coord) override; //renvoie vrai si le Player partage une case avec un Ennemies
	virtual void MoveEntity(char keyboad, Coordinates direction) override;//Prend un char et les coordonnées actuelles du Player pour le déplacer  selon le char
	char ReadPlayerInput();//lit l'input du Player
	virtual void OnEnnemy() = 0;//le Warrior et le Mage ont des interractions différentes en touchant un ennemi

private:
	char keyboard = 'a';
};