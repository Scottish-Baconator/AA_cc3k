/*
 * shade.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef SHADE_H_
#define SHADE_H_
#include "player.h"

class shade: public player{
public:
	shade(coord pos);
	double scoreMultiplier() const override;
};



#endif /* SHADE_H_ */
