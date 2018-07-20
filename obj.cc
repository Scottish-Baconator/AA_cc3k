/*
 * obj.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: ajsme
 */
#include "obj.h"

	coord obj::step(level *f){
		(void)f;
		return pos;
	}
	coord obj::getPos(){return pos;}

	char obj::render(){
		return 'O';
	}


