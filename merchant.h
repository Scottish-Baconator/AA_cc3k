/*
 * merchant.h
 *
 *  Created on: Jul 13, 2018
 *      Author: ajsme
 */

#ifndef MERCHANT_H_
#define MERCHANT_H_

#include "enemy.h"

class merchant: public enemy{
	//static bool friendly;
public:

	static bool merchantHostile();

	static void merchantAttacked();

	merchant(coord pos); //calls enemy constructor with required params

	char render() override;

	//merchants cant be attacked by enemies, so this only needs to happen when any merchant has their HP changed
	//If any merchant object gets "attacked" (called by chngHP), then
	void attacked(){
		merchantAttacked();
	}
};



#endif /* MERCHANT_H_ */
