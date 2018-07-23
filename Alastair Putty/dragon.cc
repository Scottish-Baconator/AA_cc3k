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
bool dragon::closePC(const level  *const f) const{
	for(int i = 0;i < 30;i++){
		for(int j = 0;j < 79;j++){
			if(!f->empty(coord(j, i)) && f->getObj(coord(j, i))->render() == '@'){
				return (abs(j - pos.x) <= 1 && abs(i - pos.y) <= 1)
						|| (abs(j - treasure->getPos().x) <= 1 && abs(i - treasure->getPos().y) <= 1);
			}
		}
	}
	return false;
}
