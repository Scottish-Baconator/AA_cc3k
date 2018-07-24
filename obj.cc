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
	coord obj::getPos() const{
		return pos;
	}

	void obj::chngPos(coord c){
		pos = c;
	}

	obj::obj(coord c):pos{c}{
	}

	obj::~obj(){

	}
