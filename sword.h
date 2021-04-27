/*
 * sword.h
 *
 *  Created on: Jul 25, 2018
 *      Author: alicy
 */

#ifndef SWORD_H_
#define SWORD_H_
#include "item.h"
class player;

class sword: public item{
	int bonus;
public:
	sword(coord c, int b);
	char render() const;
	player *effect(player * p);
	void displayEffect(action *a, player *p);
};


#endif /* SWORD_H_ */
