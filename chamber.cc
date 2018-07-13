/*
 * chamber.cc
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */
#include "chamber.h"
#include <cstdlib>

coord chamber::random(){
	int r = rand() % coords.size();
	return coords[r];
}

void chamber::addCoord(coord a){
	coords.emplace_back(a);
}

bool chamber::containsCoord(coord a){
	for(size_t i = 0;i < coords.size();i++){
		if(a.eq(coords[i])){
			return true;
		}
	}
	return false;
}
