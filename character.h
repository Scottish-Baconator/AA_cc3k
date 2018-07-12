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
	
	//attack does not get overriden so "resolving combat" stays generalized
	void attack(character *subj){
		int dmg;
		if(subj->dodge()){
			dmg = 0;
		}else {
			dmg = ceil((100/(100+toAtk->getDef()))*(this->getAtk()));
			dmg = atkEffect(subj, dmg);
			subj->changeHP(-dmg);
		}
		
	}; 
	
	virtual void atkEffect(character *subj, int dmg)=0; //both players and enemies can have an atkEffect (vampire; elf)
	virtual void die()=0; //Called by chngHP if HP<0 (or is it 1)
	
	void chngHP(int);
	
	int getHP(){return hp;}
	int getAtk(){return atk;}
	int getDef(){return def;}
	
	void chngHP(int p);
	
	//Drain goes here since it's called by atkEffect (so enemies can have a drain effect if we want)
	virtual int drain() { return 5; }
	
	//By default, characters never dodge
	virtual bool dodge(){
		return false;
	}
	
	
};



#endif /* CHARACTER_H_ */
