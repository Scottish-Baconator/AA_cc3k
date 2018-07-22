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

char dragon::render(){
	return 'D';
}

void dragon::drop(level *f){
	treasure->unprotectHoard();
	f->remove(pos);
}

bool dragon::closePC(level *f){
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
