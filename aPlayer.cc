/*
 * aPlayer.cc
 *
 *  Created on: Jul 25, 2018
 *      Author: alicy
 */
#include "aPlayer.h"

aPlayer::aPlayer(player *play, int val): pPlayer(play){
	protection = val;
}

double aPlayer::armour() const{
	return plaer->armour() + protection;
}

