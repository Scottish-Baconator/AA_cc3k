/*
 * pPlayer.h
 *
 *  Created on: Jul 14, 2018
 *      Author: alicy
 */

#ifndef PPLAYER_H_
#define PPLAYER_H_

#include "player.h"

//"Decorator" Class
//Player gets decorated with potions to track buffs/debuffs
class pPlayer: public player{
protected:
	player *plaer = nullptr;
public:
	pPlayer(player *p);
	~pPlayer();
};



#endif /* PPLAYER_H_ */
