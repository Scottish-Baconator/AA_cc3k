/*
 * bugbear.h
 *
 *  Created on: Jul 25, 2018
 *      Author: alicy
 */

#ifndef BUGBEAR_H_
#define BUGBEAR_H_
#include "enemy.h"

class bugbear: public player{
public:
	bugbear(coord pos);
	double armour() const;
	double scoreMultiplier() const;
};



#endif /* BUGBEAR_H_ */
