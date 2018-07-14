/*
 * player.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "character.h"

class player: public character{
	int maxHP;
public:
	player(coord pos, int hp, int atk, int def);
	
	char render();
	

	//Player dodges half the time
	int dodgeChance() override;
	
	coord step() override;
};



#endif /* PLAYER_H_ */
