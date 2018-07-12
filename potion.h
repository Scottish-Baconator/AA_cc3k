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

class potion: public item, public player{
protected:
	player *plaer;
};



#endif /* POTION_H_ */
