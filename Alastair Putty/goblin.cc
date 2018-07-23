/*
 * goblin.cc
 *
 *  Created on: Jul 20, 2018
 *      Author: alicy
 */
#include "goblin.h"
#include "player.h"

goblin::goblin(coord pos) : player{pos, 110, 15, 20, "Goblin"}{}

bool goblin::smallWeakness() const{
	return true;
}

bool goblin::canSteal() const{
	return true;
}

