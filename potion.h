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
	potion(coord pos, type t);
	char render() const;
	player* effect(player *p);
	void displayEffect(action *a, player *p);
};


#endif /* POTION_H_ */
