/*
 * chamber.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef CHAMBER_H_
#define CHAMBER_H_
#include <vector>
#include <cstdlib>
#include "coord.h"

class chamber{
	std::vector<coord> coords;
public:
	//returns a random coordinate in the chamber
	coord random();
	
	//Adds coordinate to chamber
	void addCoord(coord a);
	
	//Checks if the given coordinate is in this chamber
	bool containsCoord(coord a);
};


#endif /* CHAMBER_H_ */
