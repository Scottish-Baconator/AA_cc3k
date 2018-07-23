/*
 * vampire.cc
 *
 *  Created on: Jul 13, 2018
 *      Author: ajsme
 */


#include "player.h"
#include "vampire.h"

vampire::vampire(coord pos) : player{pos,50,25,25,"Vampire"} {}

int vampire::atkEffect(character *const subj, int dmg){
	chngHP(subj->drain());
	return dmg;
}

bool vampire::ignoreMHP() const{
	return true;
}
