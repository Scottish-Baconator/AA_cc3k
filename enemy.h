/*
 * enemy.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include "character.h"

class enemy: public character{
public:
	void drop(floor &f);
	void step(floor &f);
};



#endif /* ENEMY_H_ */
