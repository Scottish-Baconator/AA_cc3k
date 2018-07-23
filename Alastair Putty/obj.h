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
class action;

class obj{
protected:
	coord pos;
public:
	obj(coord c);
	virtual ~obj();
	virtual coord step(level *f, action *a);
	coord getPos() const;

	virtual char render() const = 0;
};



#endif /* OBJ_H_ */
