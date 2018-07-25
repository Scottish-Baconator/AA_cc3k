/*
 * sword.cc
 *
 *  Created on: Jul 25, 2018
 *      Author: alicy
 */
#include "sword.h"
#include "player.h"
#include "sPlayer.h"
#include "action.h"

sword::sword(coord c, int b): item(c){
	bonus = b;
}
char sword::render() const{
	return 'S';
}

player* sword::effect(player *p){
	return new sPlayer(p, bonus);
}

void sword::displayEffect(action *a, player *p){
	(void)p;
	a->pickUp();
}




