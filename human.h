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
	void drop(level *f) override;//drop 2 gold
public:
	human(); //calls enemy constructor with required params
	char render() override;
	void step(level *f) override;//
};


#endif /* HUMAN_H_ */
