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
	bool merchantFriend=true;
	
public:
	player(coord pos, int hp, int atk, int def);
	
	char render();
	
	//Player dodges half the time
	int dodgeChance() override;
	
	void step() override;
	void merchantKiller(); //Called when the player attacks a merchant
	//Al: I feel like this should be implemented in game.
	//An: ok that makes sense
};



#endif /* PLAYER_H_ */
