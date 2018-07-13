/*
 * floor.cc
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */
#include "floor.h"

//Checks if a chamber contains coordinate
bool is(chamber** chmbrs, coord c){
	for(int i = 0;i < 5;i++){
		if((chmbrs[i] != nullptr)&&(chmbrs[i]->containsCoord(c))){
			return true;
		}
	}
	return false;
}

//Reads map from file and determines the level layout
level::level(std::string file){
	td = new textDisplay(file);
	
	for(int i = 0;i < 30;i++){//rows
		for(int j = 0;j < 79;j++){//cols
			grd[i][j] = nullptr;
			switch(td->get(coord(j, i))){
			case '.':
				can[i][j] = All;
				break;
			case '+':
				can[i][j] = PC;
				break;
			case '#':
				can[i][j] = PC;
				break;
			case '|':
				can[i][j] = No;
				break;
			case '-':
				can[i][j] = No;
				break;
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

//Notifies all objects on level to run their step
void level::step(){
	for(int i = 0;i < 79;i++){
			for(int j = 0;j < 30;j++){
				if(grd[j][i] != nullptr){
					grd[j][i]->step();
				}
			}
		}
}

void level::add(obj* toAdd, coord pos){
	if(grd[pos.x][pos.y] == nullptr){
		grd[pos.x][pos.y] = toAdd;
	}else{
		delete toAdd;
	}
}

bool level::move(coord f, coord t){
	if(grd[t.x][t.y] == nullptr){
		grd[t.x][t.y] = grd[f.x][f.y];
		grd[f.x][f.y] = nullptr;
		return true;
	}
	return false;
}

//Gets the character of the object at coordinate c
char level::render(coord c){
	if(grd[c.x][c.y] == nullptr){
		return td->render(c);
	}else{
		return grd[c.x][c.y]->render();
	}
}

level::~level(){
	delete td;
	for(int j = 0;j < 30;j++){
		for(int i = 0;i < 79;i++){
			if(grd[i][j] != nullptr){
				delete grd[i][j];
			}

		}
	}
	for(int i = 0;i < 5;i++){
		delete chmbrs[i];
	}
}

level::Walk level::canWalk(coord c){
	if(grd[c.x][c.y] == nullptr){
		return can[c.x][c.y];
	}
	return No;
}

