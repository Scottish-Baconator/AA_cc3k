/*
 * chamber.cc
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */
#include "chamber.h"

coord chamber::random(){
	int r = rand() % coord.size();
	return coords[r];
}

void chamber::include(coord a){
	coords.emplace_back(a);
}

bool chamber::is(coord a){
	bool found = false;
	
	for(auto it = coords.begin(); it != coords.end(); ++i){
		if(a == *it){
			return found;
		}
	}
	return false;
}
