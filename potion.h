/*
 * potion.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef POTION_H_
#define POTION_H_
#include "item.h"
#include "player.h"
#include "potions.h"

//"Decorator" Class
//Player gets decorated with potions to track buffs/debuffs
class pPlayer: public player{
protected:
	player *plaer;
public:
	pPlayer(player *p): plaer(p){};
	~pPlayer(){
		delete plaer;
	}
};

class potion: public item{
	enum type{RH, BA, BD, PH, WA, WD};
	enum type what;
public:
	potion(enum type t): what(t){};
	char render(){return 'P';}
	player* effect(player *p){
		switch(what){
		case RH:
			p->chngHP(10);
			return p;
		case PH:
			p->chngHP(-10);
			return p;
		case BA:
			player tr = new BAtk(p);
			return tr;
		case BD:
			player tr = new BDef(p);
			return tr;
		case RH:
			player tr = new WAtk(p);
			return tr;
		case RH:
			player tr = new WDef(p);
			return tr;
		}
		return p;
	}
};


#endif /* POTION_H_ */
