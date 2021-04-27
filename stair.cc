/*
 * stair.cc
 *
 *  Created on: Jul 15, 2018
 *      Author: alicy
 */
#include "stair.h"

stair::stair(coord pos): obj(pos){}

char stair::render() const{
	return '\\';
}


