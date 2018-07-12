/*
 * shade.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef SHADE_H_
#define SHADE_H_
#include "player.h"

class shade: public player{
	shade(coord pos);
	void attack(character tAtk);
	void step(floor &f);
};



#endif /* SHADE_H_ */
