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

//"Decorator" Class
//Player gets decorated with potions to track buffs/debuffs
class pPlayer: public player{
protected:
	player *plaer = nullptr;
public:
	pPlayer(player *p);
	~pPlayer();
};

class potion: public item{
	enum type{RH, BA, BD, PH, WA, WD};
	enum type what;
public:
	potion(coord pos, enum type t): item(pos), what(t){};
	char render(){return 'P';}
	player* effect(player *p);
};


#endif /* POTION_H_ */
