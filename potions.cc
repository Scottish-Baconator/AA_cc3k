/*
 * potions.cc
 *
 *  Created on: Jul 13, 2018
 *      Author: alicy
 */
#include "potions.h"
#include "pPlayer.h"

BAtk::BAtk(player *p):pPlayer{p}{}
BDef::BDef(player *p):pPlayer{p}{}
WAtk::WAtk(player *p):pPlayer{p}{}
WDef::WDef(player *p):pPlayer{p}{}

double BAtk::getAtk(){
	return plaer->getAtk() + 5*potionMulti();
}

double BDef::getDef(){
	return plaer->getDef() + 5*potionMulti();
}

double WAtk::getAtk(){
	if(plaer->getAtk() > 5){
		return plaer->getAtk() - 5*potionMulti();
	}
	return 0;
}

double WDef::getDef(){
	if(plaer->getDef() > 5){
		return plaer->getDef() - 5*potionMulti();
	}
	return 0;
}
