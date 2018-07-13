/*
 * potions.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef POTIONS_H_
#define POTIONS_H_
#include "potion.h"
#include "player.h"
class pPlayer;

class BAtk: public pPlayer {
	int getAtk();
};

class BDef: public pPlayer{
	int getDef();
};

class WAtk: public pPlayer{
	int getAtk();
};

class WDef: public pPlayer{
	int getDef();
};

#endif /* POTIONS_H_ */
