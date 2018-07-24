/*
 * elf.cc
 *
 *  Created on: Jul 15, 2018
 *      Author: alicy
 */
#include "elf.h"

elf::elf(coord pos): enemy(pos, 140, 30, 10, "Elf", true, false){}

char elf::render() const{
	return 'E';
}

bool elf::doubleAttack() const{
	return true;
}
