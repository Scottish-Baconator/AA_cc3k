/*
 * dwarf.cc
 *
 *  Created on: Jul 15, 2018
 *      Author: alicy
 */
#include "dwarf.h"

dwarf::dwarf(coord pos): enemy(pos, 100, 20, 30, "Dwarf", true, false){

}

char dwarf::render() const{
	return 'W';
}

int dwarf::drain() const{
	return -5;
}
