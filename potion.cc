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


player* potion::effect(player *p){
	switch(what){
	case RH:
		p->chngHP(10);
		return p;
	case PH:
		p->chngHP(-10);
		return p;
	case BA:
		player *tr = new BAtk(p);
		return tr;
	case BD:
		player *tr = new BDef(p);
		return tr;
	case WA:
		player *tr = new WAtk(p);
		return tr;
	case WD:
		player *tr = new WDef(p);
		return tr;
	}
	return p;
}


