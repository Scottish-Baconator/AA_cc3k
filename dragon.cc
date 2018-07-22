/*
 * dragon.cc
 *
 *  Created on: Jul 22, 2018
 *      Author: ajsme
 */

#include "dragon.h"
#include "floor.h"
#include "hoard.h"

dragon::dragon(coord pos, hoard *treasure): enemy(pos, 150, 20, 30, "Dragon", true, true), treasure{treasure}{

}

char dragon::render(){
	return 'D';
}

void dragon::drop(level *f){
	treasure->unprotectHoard();
	f->remove(pos);
}
