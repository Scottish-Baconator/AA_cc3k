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
	virtual void drop(level *f); //drop is only called by die so it can be protected
	
public:
	enemy(int hp, int atk, int def, bool hostile, bool stationary);
	
	//Player and enemy attacks can be generalized. Enemy miss chance can be an atkEffect that all enemies have?
	
	virtual ~enemy();
	void die() override;
	void step(level *f) override;
};



#endif /* ENEMY_H_ */
