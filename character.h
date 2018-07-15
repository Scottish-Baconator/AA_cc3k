/*
 * character.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "obj.h"
#include <cmath>
#include <string>

class character: public obj{
	int mhp, hp, atk, def;
	std::string name;
public:
	character(coord pos, int hp, int atk, int def, std::string name);
	virtual ~character(){}

	//attack does not get overriden so "resolving combat" stays generalized
	void attack(character *subj);
	
	virtual int atkEffect(character *subj, int dmg); //both players and enemies can have an atkEffect (vampire; elf)
	
	void chngHP(int change);
	virtual void attacked();

	
	int getHP();
	virtual int getAtk();
	virtual int getDef();
	std::string getName();
	
	//By default, enemies never dodge
	virtual int dodgeChance();


	//Special Effects:

	//Drain returns the health drain of a vamp
		//Overriden by dwarf to -5
	virtual int drain();
	virtual bool doubleAttack();
	virtual bool smallKiller();

	virtual double potionMulti();

	//Allows vampire to not have max hp. This flag lets us generalize
	virtual bool ignoreMHP();
	
	//Allows troll to regenerate HP
	virtual int regen();

	//Allows goblin to steal items
	virtual int steal();

	//Used by drow to double-attack most player races
	virtual bool canDouble();

	//Used by orcs do deal extra damage to goblins (small creatures)
	virtual bool smallWeakness();


};



#endif /* CHARACTER_H_ */
