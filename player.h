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
	int mhp;
	int atk, def;
	bool merchantFriend=true;
	
public:
	player(coord pos, int hp, int atk, int def);
	
	char render(){
		return '@';
	}
	
	//Player dodges half the time
	bool dodgeChance() override{
		return 50;
	}
	
	void step(level *f) override; //Player triggers step so empty implementation
	void merchantKiller(); //Called when the player attacks a merchant
};



#endif /* PLAYER_H_ */
