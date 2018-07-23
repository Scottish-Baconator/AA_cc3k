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

class level;
class action;

class player : public character {
	int maxHP;
	std::string race;

public:
	player(coord pos, int hp, double atk, double def, std::string race);
	
	char render() const override;
	

	//Player dodges half the time
	int dodgeChance() const override;
	std::string getRace() const;
	coord step(level *f, action *a) override;
};



#endif /* PLAYER_H_ */
