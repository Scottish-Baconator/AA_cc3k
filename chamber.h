/*
 * chamber.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef CHAMBER_H_
#define CHAMBER_H_
#include <vector>
#include "coord.h"

class chamber{
	vector<coord> coords;
public:
	coord random();
	
	//Adds coordinate to chamber
	void addCoord(coord a);
	
	//Checks if the given coordinate is in this chamber
	bool containsCoord(coord a);
};


#endif /* CHAMBER_H_ */
