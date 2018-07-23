/*
 * player.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: ajsme
 */


#include "character.h"
#include "player.h"

player::player(coord pos, int hp, double atk, double def, std::string race):character{pos,hp,atk,def,"PC"},race{race}
{
	maxHP = hp;
}

char player::render() const{
	return '@';
}

//Player dodges half the time
int player::dodgeChance() const{
	return 50;
}

coord player::step(level *f, action *a) {
	(void)f;
	(void)a;
	chngHP(regen());
	return pos;
}

std::string player::getRace() const{
	return race;
}
