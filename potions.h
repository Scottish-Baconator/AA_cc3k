/*
 * potions.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef POTIONS_H_
#define POTIONS_H_
#include "pPlayer.h"
#include "player.h"

class BAtk : public pPlayer {
public:
	BAtk(player *p);
	int getAtk() override;
};

class BDef : public pPlayer{
public:
	BDef(player *p);
	int getDef() override;
};

class WAtk : public pPlayer{
public:
	WAtk(player *p);
	int getAtk() override;
};

class WDef : public pPlayer{
public:
	WDef(player *p);
	int getDef() override;
};

#endif /* POTIONS_H_ */
