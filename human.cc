/*
 * human.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */
#include "human.h"
#include "enemy.h"
#include "floor.h"

human::human(coord pos): enemy(pos, 20, 20, 140, "Human", true, false){}

char human::render(){
	return 'H';
}

void human::drop(level *f){
	spawn(f, pos, 2);
	f->replace(new gold(pos, 2), pos);
}
