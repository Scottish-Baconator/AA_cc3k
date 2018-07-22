/*
 * goblin.h
 *
 *  Created on: Jul 13, 2018
 *      Author: ajsme
 */

#ifndef GOBLIN_H_
#define GOBLIN_H_

#include "player.h"

class goblin: public player{
public:
	goblin(coord pos);

	bool smallWeakness() override;
	bool canSteal() override;
};




#endif /* GOBLIN_H_ */
