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

class character: public obj{
	int hp, atk, def;
	
public:
	virtual ~character(coord pos, int hp, int atk, int def): obj(pos),hp{hp},atk{atk},def{def}{
	};
	virtual void attack(character *subj){};
	virtual void atkEffect(character *subj); //both players and enemies can have an atkEffect (vampire; elf)
	virtual void chngHP(int);
	virtual void die(); //Called by chngHP if HP<0 (or is it 1)
	int getHP(){return hp;}
	int getAtk(){return atk;}
	int getDef(){return def;}
	void chngHP(int p);
};



#endif /* CHARACTER_H_ */
