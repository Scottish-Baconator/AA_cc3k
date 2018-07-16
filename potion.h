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


class potion: public item{
public:
	enum type{RH, BA, BD, PH, WA, WD};
private:
	type potionType;
public:
	potion(coord pos, type t): item(pos), potionType(t){};
	char render(){return 'P';}
	player* effect(player *p);
};


#endif /* POTION_H_ */
