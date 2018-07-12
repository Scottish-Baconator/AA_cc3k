/*
 * floor.cc
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */
#include "floor.h"

floor::floor(std::string file){
	td = new textDisplay(file);
	grd = new obj[30][79];
	can = new Walk[30][79];
	for(int i = 0;i < 30;i++){//rows
		for(int j = 0;j < 79;j++){//cols
			grd[i][j] = nullptr;
			switch(td->get(coord(j, i))){
			case '.':
				can[i][j] = All;
				break;
			case '+':
			case '#':
				can[i][j] = PC;
				break;
			case '|':
			case '-':
			case ' ':
				can[i][j] = No;
				break;
			}
		}
	}
}

