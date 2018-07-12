/*
 * chamber.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef CHAMBER_H_
#define CHAMBER_H_
#include <stdlib.h>
#include "coord.h"

class chamber{
	int mSize = 0;
	int size  = 0;
	coord coords[] = nullptr;
public:
	coord random();
	void include(coord a);
};


#endif /* CHAMBER_H_ */
