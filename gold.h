/*
 * gold.h
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */

#ifndef GOLD_H_
#define GOLD_H_
#include "item.h"

class gold: public item{
	int val;
public:
	gold(int v): val(v){};
	char render(){
		return 'G';
	}
	int getVal(){return val;}
};



#endif /* GOLD_H_ */
