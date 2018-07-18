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
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "potion.h"

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
level::level(std::string file, action *a, int floorNum):floorNum{floorNum},td{new textDisplay(file, this, a)} {

	//WE'RE GONNA HAVE TO METHODIZE THIS EVENTUALLY RIP
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
					cur++;
				}
			}
			if(cur > 4){
				break;
			}
		}
		if(cur > 4){
			break;
		}
	}

	for(int i = 0;i < 10;i++){
			coord tem = chmbrs[rand()%5]->random();
			potion::type t;
			switch (rand()%6) {
			case 0:
				t = potion::RH;
				break;
			case 1:
				t = potion::PH;
				break;
			case 2:
				t = potion::BA;
				break;
			case 3:
				t = potion::BD;
				break;
			case 4:
				t = potion::WA;
				break;
			case 5:
				t = potion::WD;
				break;
			}
			add(new potion(tem, t), tem);
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


	//God I don't want to spawn enemies.

	char toSpwn[20];
	for(int i = 0;i < 20;i++){
		switch (rand()%18){
		case 0:
		case 1:
		case 2:
		case 3:
			toSpwn[i] = 'H';
			break;
		case 4:
		case 5:
		case 6:
			toSpwn[i] = 'W';
			break;
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
			toSpwn[i] = 'L';
			break;
		case 12:
		case 13:
			toSpwn[i] = 'E';
			break;
		case 14:
		case 15:
			toSpwn[i] = 'O';
			break;
		case 16:
		case 17:
			toSpwn[i] = 'M';
			break;
		}
	}
	for(int i = 0;i < 20;i++){
		int chm = rand()%5;
		coord a(0, 0);
		do{
			a = getChmbr(chm)->random();
		}while(canWalk(a) != level::All);
		switch (toSpwn[i]){
		case 'H':
			add(new human(a), a);
			break;
		case 'W':
			add(new dwarf(a), a);
			break;
		case 'L':
			add(new halfling(a), a);
			break;
		case 'E':
			add(new elf(a), a);
			break;
		case 'O':
			add(new orc(a), a);
			break;
		case 'M':
			add(new merchant(a), a);
			break;
		}
	}
}

bool level::empty(coord c){
	if(c.x>=79 || c.y >=30 || c.x < 0 || c.y<0){
		return false;
	}
	return (grd[c.x][c.y]==nullptr);
}

//Notifies all objects on level to run their step
void level::step(){
	bool ignore[79][30];
	//std::cerr << "hello " << std::endl;

	for(int i = 0;i < 79;i++){
		for(int j = 0;j < 30;j++){
			ignore[i][j] = false;
		}

	}
	for(int i = 0;i < 79;i++){
		for(int j = 0;j < 30;j++){
			if((!ignore[i][j])&&(grd[i][j] != nullptr)){
			//	std::cerr << "hi " << std::endl;
				coord t = grd[i][j]->step(this);
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


void level::update(obj *toAdd, coord pos){
	grd[pos.x][pos.y] = toAdd;
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
void level::render(std::ostream &out, player *p, int gld){
	td->render(out, p, gld);
}

level::~level(){
	for(int i = 0;i < 79;i++){
		for(int j = 0;j < 30;j++){
			if(grd[i][j]!=nullptr){
				delete grd[i][j];
			}

		}
	}
	for(int i = 0;i < 5;i++){
		delete chmbrs[i];
	}
	delete td;
}

void level::remove(coord c){
	delete grd[c.x][c.y]; //if it's nullptr this is still fine
	grd[c.x][c.y]=nullptr; //avoid segfault
}

level::Walk level::canWalk(coord c){
	//if(grd[c.x][c.y] == nullptr){
		return can[c.x][c.y];
	//}
	//return No;
}

int level::getFloorNum(){
	return floorNum;
}

