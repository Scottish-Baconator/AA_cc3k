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
	
protected:
	bool isHostile;
	bool isStationary;
	
public:
	enemy(coord pos, int hp, int atk, int def, bool hostile, bool stationary);
	
	//NOTE::: ENEMY IS CURRENTLY NOT ABSTRACT
	//I don't think we can just make the dtor abstract though can we???
	
	virtual void drop(level *f); 
	virtual ~enemy();
	void step(level *f);
};



#endif /* ENEMY_H_ */
