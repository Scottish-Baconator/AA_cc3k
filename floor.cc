/*
 * floor.cc
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */
#include "floor.h"
#include "gold.h"
#include "textdisplay.h"
#include <iostream>
#include <cstdlib>

//Checks if a chamber contains coordinate
bool is(chamber** chmbrs, coord c){
	for(int i = 0;i < 5;i++){
		if(chmbrs[i]->containsCoord(c)){
			return true;
		}
	}
	return false;
}

//Reads map from file and determines the level layout
level::level(std::string file){

	td = new textDisplay(file, this);

	for(int i = 0;i < 79;i++){//rows
		for(int j = 0;j < 30;j++){//cols
			grd[i][j] = nullptr;
			switch(td->get(coord(i, j))){
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

	for(int i = 0;i < 79;i++){
		for(int j = 0;j < 30;j++){
			grd[i][j]=nullptr;
		}
	}
	for(int i=0;i<5;++i){
		chmbrs[i] = new chamber();
	}

	int cur = 0;


	for(int i = 0;i < 79;i++){
		for(int j = 0;j < 30;j++){
			if(td->get(coord(i, j)) == '.'){
				if(!is(chmbrs, coord(i, j))){
					td->chambFrom(coord(i,j), chmbrs[cur]);
					cur+=1;
				}
			}
		}
	}

	for(int i=0; i<10; ++i){

		int chamberid;
		coord gc(0,0);
		gold* g;

		int goldrand = rand() % 8;

		do{
		chamberid= rand() % 5;
		gc= chmbrs[chamberid]->random();
		}while(!empty(gc));

		if(goldrand < 5){
			g = new gold{gc, 2};
		} else {
			g = new gold{gc, 1};

		}

		grd[gc.x][gc.y]=g;
	}
}

bool level::empty(coord c){
	return (grd[c.x][c.y]==nullptr);
}

//Notifies all objects on level to run their step
void level::step(){
	bool ignore[79][30];
	for(int i = 0;i < 79;i++){
		for(int j = 0;j < 30;j++){
			ignore[i][j] = false;
		}
	}
	for(int i = 0;i < 79;i++){
		for(int j = 0;j < 30;j++){
			if((!ignore[i][j])&&(grd[i][j] != nullptr)){
				coord t = grd[i][j]->step();
				ignore[t.x][t.y] = true;
			}
		}
	}
}

void level::add(obj *toAdd, coord pos){
	if(grd[pos.x][pos.y] == nullptr){
		grd[pos.x][pos.y] = toAdd;
	}else{
		delete toAdd;
	}
}

bool level::move(coord origin, coord target){
	if(empty(target)){
		grd[target.x][target.y] = grd[origin.x][origin.y];
		grd[origin.x][origin.y] = nullptr;
		return true;
	}

	return false;
}

//Gets the character of the object at coordinate c
void level::render(std::ostream &out, player *p){
	td->render(out, p);
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

void level::remove(coord c){
	delete grd[c.x][c.y]; //if it's nullptr this is still fine
	grd[c.x][c.y]=nullptr; //avoid segfault
}

level::Walk level::canWalk(coord c){
	if(grd[c.x][c.y] == nullptr){
		return can[c.x][c.y];
	}
	return No;
}

