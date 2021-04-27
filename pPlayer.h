/*
 * pPlayer.h
 *
 *  Created on: Jul 14, 2018
 *      Author: alicy
 */

#ifndef PPLAYER_H_
#define PPLAYER_H_

#include "player.h"

//"Decorator" Class
//Player gets decorated with potions to track buffs/debuffs
class pPlayer: public player{
protected:
	player *plaer = nullptr;
public:
	pPlayer(player *p);
	~pPlayer();
	//Drain returns the health drain of a vamp
		//Overriden by dwarf to -5
	int drain() const override;

	//Allows character to attack twice
	bool doubleAttack() const override;

	//Steals upon killing an enemy
	bool canSteal() const override;

	//Multiplier to change potion effectiveness
	double potionMulti() const override;

	//Allows vampire to not have max HP.
	bool ignoreMHP() const override;

	//Allows troll to regenerate HP
	 int regen() const override;

	//Allows goblin to steal items
	 int stealAmt() const override;

	//Used by drow to double-attack most player races
	 bool canDouble() const override;

	//Used by orcs do deal extra damage to goblins (small creatures)
	 bool smallWeakness() const override;
};



#endif /* PPLAYER_H_ */
