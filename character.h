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
	
	void chngHP(int);
	
	int getHP(){return hp;}
	int getAtk(){return atk;}
	int getDef(){return def;}
	
	//Drain goes here since it's called by atkEffect (so enemies can have a drain effect if we want)
	virtual int drain() { return 5; }
	
	//By default, enemies never dodge
		//Al: Why not return a chance of dodging, so that if subj and this have an effect they can deal with it.
	virtual int dodgeChance(){
		return 0;
	}
	
	
};



#endif /* CHARACTER_H_ */
