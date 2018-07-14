/*
 * pPlayer.cc
 *
 *  Created on: Jul 14, 2018
 *      Author: alicy
 */
#include "pPlayer.h"

pPlayer::pPlayer(player *p): player(p->getPos(), p->getHP(), p->getAtk(), p->getDef()){
	plaer = p;
}

pPlayer::~pPlayer(){
	delete plaer;
}


