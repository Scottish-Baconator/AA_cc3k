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


