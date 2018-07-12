/*
 * chamber.cc
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */
#include "chamber.h"

coord chamber::random(){
	int r = rand() % size;
	return coords[r];
}

void chamber::include(coord a){
	if(size == 0){
		mSize = 5;
		coords = new coord[5];
	}
	else if(size == mSize){
		coord temp[mSize];
		for(int i = 0;i < mSize;i++){
			temp[i] = coords[i];
		}
		delete coords;
		coords = new coord[mSize*2];
		for(int i = 0;i < mSize;i++){
			coords[i] = temp[i];
		}
		mSize *= 2;
	}
	coords[size++] = a;
}


