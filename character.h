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
	virtual ~character(coord pos, int h, int a, int d): obj(pos){
		hp = h;
		atk = a;
		def = d;
	};
	virtual void attack(character subj){};
	virtual void chngHP(int);
	virtual int getHP(){return hp;}
	virtual int getAtk(){return atk;}
	virtual int getDef(){return def;}
};



#endif /* CHARACTER_H_ */
