/*
 * orc.cc
 *
 *  Created on: Jul 15, 2018
 *      Author: alicy
 */

#include "orc.h"

orc::orc(coord pos): enemy(pos, 180, 30, 25, "orc", true, false){}

char orc::render() const{
	return 'O';
}

int orc::atkEffect(character* subj, int dmg){
	if(subj->smallWeakness()){
		dmg*=1.5;
	}
	return dmg;
}

