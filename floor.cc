/*
 * floor.cc
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */
#include "floor.h"

floor::floor(){
	grd = new obj[30][79];
	for(int i = 0;i < 30;i++){//rows
		for(int j = 0;j < 79;j++){//cols
			grd[i][j] = nullptr;
		}
	}
}

