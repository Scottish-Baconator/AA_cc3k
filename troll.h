/*
 * troll.h
 *
 *  Created on: Jul 13, 2018
 *      Author: ajsme
 */

#ifndef TROLL_H_
#define TROLL_H_


#include "player.h"

class troll: public player{
public:
	troll(coord pos);

	int regen() override;
};





#endif /* TROLL_H_ */
