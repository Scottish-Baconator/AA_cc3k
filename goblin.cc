/*
 * goblin.cc
 *
 *  Created on: Jul 20, 2018
 *      Author: alicy
 */
#include "goblin.h"

goblin::goblin(coord pos): player(pos, 110, 15, 20, "Goblin"){}

int goblin::atkEffect(character *subj, int dmg){
	return dmg;
}

bool goblin::smallWeakness(){
	return true;
}
