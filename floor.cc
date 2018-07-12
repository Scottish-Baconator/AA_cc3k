/*
 * floor.cc
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */
#include "floor.h"

bool is(chamber* chmbrs, coord c){
	for(int i = 0;i < 5;i++){
		if((chmbrs[i] != nullptr)&&(chmbrs[i].is(c))){
			return true;
		}
	}
	return false;
}

level::level(std::string file){
	td = new textDisplay(file);
	grd = new obj[30][79];
	can = new Walk[30][79];
	chmbrs = new chamber[5];
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
	int cur = 0;
	for(int i = 0;i < 79;i++){
		for(int j = 0;j < 30;j++){
			if(td->get(coord(i, j)) == '.'){
				if(!is(chmbrs, coord(i, j))){
					td->chambFrom(coord(i,j), chmbrs[cur++]);
				}
			}
		}
	}
}

