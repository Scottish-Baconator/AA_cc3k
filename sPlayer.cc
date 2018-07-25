/*
 * aPlayer.cc
 *
 *  Created on: Jul 25, 2018
 *      Author: alicy
 */
#include "sPlayer.h"

sPlayer::sPlayer(player *play, int val): pPlayer(play){
	bonus = val;
}

int sPlayer::getAtk(){
	return plaer->getAtk() + bonus;
}

