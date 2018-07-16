/*
 * player.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "character.h"
#include <string>

class player : public character {
	int maxHP;
	std::string name;

public:
	player(coord pos, int hp, double atk, double def, std::string name);
	
	char render();
	

	//Player dodges half the time
	int dodgeChance() override;
	
	coord step() override;
};



#endif /* PLAYER_H_ */
