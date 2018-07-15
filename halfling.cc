/*
 * halfling.cc
 *
 *  Created on: Jul 15, 2018
 *      Author: alicy
 */
#include "halfling.h"

halfling::halfling(coord pos): enemy(pos, 100, 15, 20, "halfling", true, false){}

char halfling::render(){
	return 'L';
}

int halfling::dodgeChance(){
	return 50;
}

