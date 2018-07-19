/*
 * human.h
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */

#ifndef HUMAN_H_
#define HUMAN_H_
#include "enemy.h"
#include "gold.h"

class human: public enemy{
protected:
public:
	human(coord pos); //calls enemy constructor with required params
	char render() override;
	void drop(level *f) override;//drop 2 gold
};


#endif /* HUMAN_H_ */
