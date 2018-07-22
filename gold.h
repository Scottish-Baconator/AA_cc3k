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
protected:
	bool canPick;
public:
	gold(coord pos, int v, bool pickable=true): item(pos), val(v), canPick{pickable}{
	};
	char render(){
		return 'G';
	}
	int getVal(){
		return val;
	}
	bool getPick(){
		return canPick;
	}
};



#endif /* GOLD_H_ */
