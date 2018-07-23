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
	gold(coord pos, int v, bool pickable=true);

	char render() const override;

	int getVal() const;

	bool getPick() const;
};



#endif /* GOLD_H_ */
