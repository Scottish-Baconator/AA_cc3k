/*
 * potions.cc
 *
 *  Created on: Jul 13, 2018
 *      Author: alicy
 */
#include "potions.h"

int BAtk::getAtk(){
	return plaer->getAtk() + 5;
}

int BDef::getDef(){
	return plaer->getDef() + 5;
}

int WAtk::getAtk(){
	if(plaer->getAtk() > 5){
		return plaer->getAtk() - 5;
	}
	return 0;
}

int WDef::getDef(){
	if(plaer->getDef() > 5){
		return plaer->getDef() - 5;
	}
	return 0;
}
