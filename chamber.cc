/*
 * chamber.cc
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */
#include "chamber.h"
#include <cstdlib>
#include <iostream>
#include <vector>

coord chamber::random(){
	int r = rand() % coords.size();
	return coords[r];
}

void chamber::addCoord(coord a){
	coords.emplace_back(a);
}

bool chamber::containsCoord(coord a){
	bool result=false;
	/*
	for(size_t i=0; i<coords.size(); ++i){
		if(a.eq(coords[i])){
			result=true;
			break;
		}
	}*/

	for(auto it = coords.begin(); it != coords.end(); it++){
		if(a.eq(*it)){
			result=true;
			break;
		}
	}

	return result;
}
