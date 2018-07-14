/*
 * halfling.h
 *
 *  Created on: Jul 13, 2018
 *      Author: ajsme
 */

#ifndef HALFLING_H_
#define HALFLING_H_


#include "enemy.h"

class halfling: public enemy{
	public:
		halfling(coord pos); //calls enemy constructor with required params

		char render() override;

		//Halfling dodges half the time
		int dodgeChance() override;
};


#endif /* HALFLING_H_ */
