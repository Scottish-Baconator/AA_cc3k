/*
 * obj.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef OBJ_H_
#define OBJ_H_
#include "coord.h"

class level;

class obj{
protected:
	coord pos;
public:
	obj(coord c): pos(c){}
	virtual ~obj(){};
	virtual coord step(level *f);
	coord getPos();
	virtual char render();
};



#endif /* OBJ_H_ */
