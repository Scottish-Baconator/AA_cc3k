/*
 * character.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */
#include "character.h"

void character::attack(character *subj){
	int dmg;
	if(rand() % 100 < subj->dodgeChance()){
		dmg = 0;
	}else {
		dmg = ceil((100/(100+subj->getDef()))*(this->getAtk()));
		dmg = atkEffect(subj, dmg);
		subj->chngHP(-dmg);
	}
}

void character::chngHP(int p){
	hp += p;
}


