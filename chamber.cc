/*
 * chamber.cc
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */
#include "chamber.h"
#include <cstdlib>
#include <vector>
#include "time.h"

coord chamber::random() const{
	int r = rand() % coords.size();
	return coords[r];
}

void chamber::addCoord(const coord a){
	coords.emplace_back(a);
}

bool chamber::containsCoord(const coord a) const{
	bool result=false;

	for(auto it = coords.begin(); it != coords.end(); it++){
		if(a.eq(*it)){
			result=true;
			break;
		}
	}

	return result;
}
