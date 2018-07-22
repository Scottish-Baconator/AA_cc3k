/*
 * obj.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: ajsme
 */
#include "obj.h"

	coord obj::step(level *f, action *a){
		(void)f;
		(void)a;
		return pos;
	}
	coord obj::getPos(){return pos;}

	char obj::render(){
		return 'O';
	}


