/*
 * aPlayer.h
 *
 *  Created on: Jul 25, 2018
 *      Author: alicy
 */

#ifndef APLAYER_H_
#define APLAYER_H_
#include "pPlayer.h"

class aPlayer: public pPlayer{
	int protection;
public:
	aPlayer(player*, int);
	double armour()  const override;
};



#endif /* APLAYER_H_ */
