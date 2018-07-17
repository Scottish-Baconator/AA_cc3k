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

char player::render(){
	return '@';
}

//Player dodges half the time
int player::dodgeChance(){
	return 50;
}

coord player::step() {
	chngHP(regen());
	return pos;
}

std::string player::getRace(){
	return race;
}
