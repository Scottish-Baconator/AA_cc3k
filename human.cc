/*
 * human.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */
#include "human.h"

human::human(){
	enemy(20, 20, 140);
}

char human::render(){
	return 'H';
}

void human::drop(level *f){
	f->add(new gold(4), pos);
}
