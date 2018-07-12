/*
 * obj.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef OBJ_H_
#define OBJ_H_
#include "coord.h"

class obj{
protected:
	coord pos;
public:
	virtual obj(coord);
	virtual ~obj(){};
	virtual char render();
};



#endif /* OBJ_H_ */
