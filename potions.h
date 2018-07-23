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

class action;

class BAtk : public pPlayer {
public:
	BAtk(player *p);
	double getAtk() const override;
};

class BDef : public pPlayer{
public:
	BDef(player *p);
	double getDef() const override;
};

class WAtk : public pPlayer{
public:
	WAtk(player *p);
	double getAtk() const override;
};

class WDef : public pPlayer{
public:
	WDef(player *p);
	double getDef() const override;
};

#endif /* POTIONS_H_ */
