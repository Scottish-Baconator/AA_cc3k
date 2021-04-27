/*
 * dragon.cc
 *
 *  Created on: Jul 22, 2018
 *      Author: ajsme
 */

#include "dragon.h"
#include "floor.h"
#include "hoard.h"
#include <cmath>
#include <cmath>

dragon::dragon(coord pos, hoard *treasure): enemy(pos, 150, 20, 30, "Dragon", true, true), treasure{treasure}{

}

char dragon::render() const{
	return 'D';
}

//Frees the hoard to be picked up when dragon dies
void dragon::drop(level *f){
	treasure->unprotectHoard();
	f->remove(pos);
}

//Dragon can attack from range if the PC is beside its hoard
bool dragon::closePC(level  *const f) const{
	return f->close(this,f->getPC()) ||  f->close(treasure,f->getPC());
}
