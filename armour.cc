/*
 * armour.cc
 *
 *  Created on: Jul 25, 2018
 *      Author: alicy
 */
#include "armour.h"
#include "aPlayer.h"
#include "action.h"

armour::armour(coord pos, int v): item(pos){
	val = v;
}

char armour::render() const{
	return 'A';
}

player* armour::effect(player* p){
	return new aPlayer(p, val);
}

void armour::displayEffect(action *a, player *p){
	(void)p;
	a->addArmour(val);
}

