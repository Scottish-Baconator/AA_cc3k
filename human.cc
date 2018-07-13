/*
 * human.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */
#include "human.h"
#include "enemy.h"

human::human(coord pos): enemy(pos, 20, 20, 140, true, false){}

char human::render(){
	return 'H';
}

void human::drop(level *f){
	coord tA = pos;
	tA.x++;
	f->add(new gold(tA, 4), tA);
}
