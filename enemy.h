/*
 * enemy.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include "character.h"
#include "floor.h"

class enemy: public character{
public:
	enemy(int a, int d, int h);
	virtual ~enemy();
	virtual void atkEffect(character *toAtk);
	void attack(character *toAtk);
	void step(level *f);
	void drop(level *f);
};



#endif /* ENEMY_H_ */
