/*
 * pPlayer.cc
 *
 *  Created on: Jul 14, 2018
 *      Author: alicy
 */
#include "pPlayer.h"
#include "player.h"

pPlayer::pPlayer(player *p): player(p->getPos(), p->getHP(), p->getAtk(), p->getDef(), p->getRace()), plaer{p}{
}

pPlayer::~pPlayer(){
	delete plaer;
}


int pPlayer::drain() const{
	return plaer->drain();
}

bool pPlayer::doubleAttack() const{
	return plaer->doubleAttack();
}
bool pPlayer::canSteal() const{
	return plaer->canSteal();
}

//Allows vampire to not have max hp. This flag lets us generalize
bool pPlayer::ignoreMHP() const{
	return plaer->ignoreMHP();
}

double pPlayer::potionMulti() const{
	return plaer->potionMulti();
}

//Allows troll to regenerate HP
int pPlayer::regen() const{
	return plaer->regen();
}

//Allows goblin to steal gold. Default is 5
int pPlayer::stealAmt() const{
	return plaer->stealAmt();
}

//Used by drow to double-attack most player races
bool pPlayer::canDouble() const{
	return plaer->canDouble();
}

//Used by orcs do deal extra damage to goblins
bool pPlayer::smallWeakness() const{
	return plaer->smallWeakness();
}

