/*
 * item.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef ITEM_H_
#define ITEM_H_
#include "obj.h"

class item: public obj{
public:
	item(coord pos): obj(pos){};
	virtual ~item(){}; //Virtual dtor just so item becomes abstract

};



#endif /* ITEM_H_ */
