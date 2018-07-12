/*
 * potions.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef POTIONS_H_
#define POTIONS_H_
#include "potion.h"

class BA: public potion{
	int getAtk() override{
		return plaer->getAtk() + 5;
	}
};

class BD: public potion{
	int getDef() override{
		return plaer->getDef() + 5;
	}
};

class WA: public potion{
	int getAtk() override{
		if(plaer->getDef() > 5){
			return plaer->getDef() - 5;
		}
		return 0;
	}
};

class WD: public potion{
	int getDef() override{
		if(plaer->getDef() > 5){
			return plaer->getDef() - 5;
		}
		return 0;
	}
};

#endif /* POTIONS_H_ */
