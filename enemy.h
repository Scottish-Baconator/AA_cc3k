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
#include "gold.h"

class enemy: public character{
	coord move(level *f);
	
protected:
	bool isHostile;
	bool isStationary;
	
public:
	enemy(coord pos, int hp, double atk, double def, std::string name, bool hostile, bool stationary);
	
	virtual void drop(level *f); 
	virtual bool closePC(const level * const f) const;
	virtual ~enemy()=0;
	coord step(level *f, action *a) override;
	void spawn(level *f, const coord &pos, int val);
};



#endif /* ENEMY_H_ */
