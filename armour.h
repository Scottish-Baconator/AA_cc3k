/*
 * armour.h
 *
 *  Created on: Jul 25, 2018
 *      Author: alicy
 */

#ifndef ARMOUR_H_
#define ARMOUR_H_
#include "item.h"
#include "player.h"

class armour: public item{
	int val;
public:
	armour(coord pos, int val);
	char render() const;
	player *effect(player *p);
	void displayEffect(action *a, player *p);
};



#endif /* ARMOUR_H_ */
