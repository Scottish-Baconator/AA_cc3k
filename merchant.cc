/*
 * merchant.cc
 *
 *  Created on: Jul 15, 2018
 *      Author: alicy
 */

#include "merchant.h"

bool merchant::friendly=true;

bool merchant::merchantHostile(){
	return !merchant::friendly;
}

void merchant::merchantAttacked(){
	merchant::friendly=false;
}

merchant::merchant(coord pos): enemy(pos, 30, 70, 5, "merchant", merchant::merchantHostile(), false){
}

char merchant::render(){
	return 'M';
}
