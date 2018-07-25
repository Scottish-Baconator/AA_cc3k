/*
 * sPlayer.h
 *
 *  Created on: Jul 25, 2018
 *      Author: alicy
 */

#ifndef SPLAYER_H_
#define SPLAYER_H_
#include "pPlayer.h"

class sPlayer: public pPlayer{
	int bonus;
public:
	sPlayer(player*, int);
	double getAtk() const override;
};



#endif /* SPLAYER_H_ */
