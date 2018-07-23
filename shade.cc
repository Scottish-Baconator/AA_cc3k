/*
 * shade.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: ajsme
 */


#include "player.h"
#include "shade.h"

shade::shade(coord pos) : player{pos,125,25,25,"Shade"} {}

double shade::scoreMultiplier() const{
	return 1.5;
}
