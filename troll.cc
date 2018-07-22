/*
 * troll.cc
 *
 *  Created on: Jul 14, 2018
 *      Author: alicy
 */
#include "troll.h"

troll::troll(coord pos): player(pos, 120, 25, 15, "Troll"){

}

int troll::regen(){
	return 5;
}


