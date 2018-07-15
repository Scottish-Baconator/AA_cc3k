/*
 * player.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: ajsme
 */


#include "character.h"
#include "player.h"

player::player(coord pos, int hp, int atk, int def, std::string name):character{pos,hp,atk,def,name}
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
