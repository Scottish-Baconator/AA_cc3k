/*
 * player.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: ajsme
 */


#include "character.h"
#include "player.h"

player::player(coord pos, int hp, int atk, int def):character{pos,hp,atk,def}
{}

char player::render(){
	return '@';
}

//Player dodges half the time
int player::dodgeChance(){
	return 50;
}

void player::step() {
	chngHP(regen());
}

void player::merchantKiller(){} //Called when the player attacks a merchant
