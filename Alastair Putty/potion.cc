/*
 * potion.cc
 *
 *  Created on: Jul 13, 2018
 *      Author: alicy
 */
class BDef;
class BAtk;
class WDef;
class WAtk;
#include "potion.h"
#include "potions.h"
#include "action.h"


potion::potion(coord pos, type t): item(pos), potionType(t){}

char potion::render() const {
	return 'P';
}

player* potion::effect(player *p){
	switch(potionType){
	case RH:
		p->chngHP(10);
		return p;
	case PH:
		p->chngHP(-10);
		return p;
	case BA:
		return new BAtk(p);
	case BD:
		return new BDef(p);
	case WA:
		return new WAtk(p);
	case WD:
		return new WDef(p);
	}
	return p;
}

void potion::displayEffect(action *a){
	switch(potionType){
		case RH:
			a->usePot("Restore Health");
			a->changeStat("HP","+",10);
			break;
		case PH:
			a->usePot("Poison Health");
			a->changeStat("HP","-",10);
			break;
		case BA:
			a->usePot("Boost Attack");
			a->changeStat("ATK","+",5);
			break;
		case BD:
			a->usePot("Boost Defense");
			a->changeStat("DEF","+",5);
			break;
		case WA:
			a->usePot("Wound Attack");
			a->changeStat("ATK","-",5);
			break;
		case WD:
			a->usePot("Wound Defense");
			a->changeStat("DEF","-",5);
			break;
	}
}
