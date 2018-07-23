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
	std::vector<coord> coords;
public:
	//Returns a random coordinate in the chamber
	coord random() const;
	
	//Adds coordinate to chamber
	void addCoord(const coord &a);
	
	//Checks if the given coordinate is in this chamber
	bool containsCoord(const coord &a) const;
};


#endif /* CHAMBER_H_ */
