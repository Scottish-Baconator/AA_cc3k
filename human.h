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
public:
	human();
	char render();
	void drop(level *f);//drop 2 gold
	void step(level *f);//
};


#endif /* HUMAN_H_ */
