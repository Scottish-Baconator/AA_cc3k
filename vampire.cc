/*
 * vampire.cc
 *
 *  Created on: Jul 13, 2018
 *      Author: ajsme
 */


#include "player.h"
#include "vampire.h"

vampire::vampire(coord pos) : player{pos,50,25,25} {}

void vampire::chngHP(int p){
	hp += p;
}

int vampire::atkEffect(character *subj, int dmg){
	chngHP(subj->drain());
	return dmg;
}

bool vampire::ignoreMHP(){
	return true;
}
