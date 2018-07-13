/*
 * character.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "obj.h"
#include "floor.h"
#include <cmath>

class character: public obj{
	int hp, atk, def;
	
public:
	character(coord pos, int hp, int atk, int def): obj(pos),hp{hp},atk{atk},def{def}{};
	virtual ~character(){}

	//attack does not get overriden so "resolving combat" stays generalized
	void attack(character *subj);
	
	virtual int atkEffect(character *subj, int dmg)=0; //both players and enemies can have an atkEffect (vampire; elf)
	
	void chngHP(int change);
	
	int getHP();
	int getAtk();
	int getDef();
	
	//By default, enemies never dodge
	virtual int dodgeChance();


	//Special Effects:
	//Drain returns the health drain of a vamp
		//Overriden by dwarf to -5
	virtual int drain();
	
};



#endif /* CHARACTER_H_ */
