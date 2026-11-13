#pragma once
#include "Utilities.h"
//Classe parente qui va être héritée par Player et Ennemies
class Entity
{
protected:
	virtual ~Entity() = default; //Pour détrtuire la classe à la fin du code
public:
	virtual bool CollidingEnemy(Coordinates coord) = 0; 
	virtual void OnEnnemy() = 0; //Player et Ennemies vont utiliser cette fonction différemment donc ils en héritent
	virtual void TakeDamage() = 0; //Idem
	bool CanMove(int new_x, int new_y); //verifie si une Entity peut utiliser la fonction déplacement
	virtual void MoveEntity(char keyboard, Coordinates direction) =0;//Player et Ennemies se déplacent différemmet
	void ApplyDamage(int damageTaken); //Applique les dégats
	bool IsAlive();//Renvoie True si une Entity possède Health>0
	//Getter
	int GetDamage();//obtient les dégats d'une Entity
	int GetHealth();// obtient les points de vie d'une Entity
	//Setter
	void SetDamage(int value);//change les dégats d'une Entity
	void SetHealth(int value);//change les points de vie d'une Entity
	void SetCoords(Coordinates coord);//change les coordonnées d'une Entity
private:
	int health = 1;
	int damage = 1;
};