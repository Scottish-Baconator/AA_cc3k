/*
 * stair.h
 *
 *  Created on: Jul 15, 2018
 *      Author: alicy
 */

#ifndef STAIR_H_
#define STAIR_H_
#include "coord.h"
#include "obj.h"

class stair: public obj{
public:
	stair(coord pos);
	char render() const override;
};



#endif /* STAIR_H_ */
