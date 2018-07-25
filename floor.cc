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
#include <ctime>
#include <cmath>
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "bugbear.h"
#include "potion.h"
#include "hoard.h"
#include "stair.h"
#include "armour.h"
#include "obj.h"

//Checks if a chamber contains coordinate
bool level::is(const coord &c) const{

	for (auto it = chmbrs.begin() ; it != chmbrs.end(); ++it) {
		if((*it)->containsCoord(c)){
			return true;
		}
	}
	return false;
}
void level::randGen(int playerChamber, bool extra){
	(void)extra;
	int stairchmbr;
	do{
		stairchmbr = getRandomChamber();
	}while(stairchmbr==playerChamber);

	coord scoord = chmbrs[stairchmbr]->random();
	add(new stair(scoord), scoord);

	for(int i = 0;i < 10;i++){
		coord tem = chmbrs[rand()%(chmbrs.size())]->random();
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
			chamberid= rand() % chmbrs.size();
			gc= chmbrs[chamberid]->random();
		}while(!empty(gc));

		if(goldrand < 5){
			g = new gold{gc, 2};
		} else if (goldrand < 7){
			g = new gold{gc, 1};
		} else { //goldrand = 7
			//Repeats finding a coordinate for gold until it can find one where
			//it can also spawn a dragon beside it
			while(enemyTrapped(gc)){
				chamberid= rand() % chmbrs.size();
				gc= chmbrs[chamberid]->random();
			}

			g = new hoard{gc, this};
		}
		grd[gc.x][gc.y]=g;
	}

	if(extra){
		coord aPos = chmbrs[stairchmbr]->random();
		if(empty(aPos)){
			add(new armour(aPos, 5), aPos);
		}
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
		int chm = rand()%chmbrs.size();
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
void level::setWalk(){
	for(int i = 0;i < 79;i++){//rows
		for(int j = 0;j < 30;j++){//cols
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

}

bool oneOf(char a, char b[], int len){
	for(int i = 0;i < len;i++){
		if(a == b[i]){
			return true;
		}
	}
	return false;
}

void level::makeChambers(){
	for(int i=0;i<5;++i){
		chmbrs.emplace_back(new chamber());
	}

	int cur = 0;
	for(int i = 0;i < 79;i++){
		for(int j = 0;j < 30;j++){
			if(td->get(coord(i, j)) == '.'){
				if(!is(coord(i, j))){
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
}


//Reads map from file and determines the level layout
level::level(std::string file, action *a, int floorNum, bool rand):floorNum{floorNum}{
	//Initializes every cell to be empty
	grd.resize(79);
	for(int i = 0;i < 79;i++){
		grd[i].resize(30);
		for(int j = 0;j < 30;j++){
			grd[i][j]=nullptr;
		}
	}
	td = new textDisplay(file, this, a, rand);
	setWalk();

	makeChambers();
}

bool level::empty(const coord &c) const{
	if(c.x>=79 || c.y >=30 || c.x < 0 || c.y<0){
		return false;
	}
	return (grd[c.x][c.y]==nullptr);
}

//Notifies all objects on level to run their step
//The use of ignore prevents enemies from moving multiple times
void level::step(action *a){
	//srand(time(0));
	bool ignore[79][30];

	for(int i = 0;i < 79;i++){
		for(int j = 0;j < 30;j++){
			ignore[i][j] = false;
		}

	}
	for(int i = 0;i < 79;i++){
		for(int j = 0;j < 30;j++){
			if((!ignore[i][j])&&(grd[i][j] != nullptr)){
				coord t = grd[i][j]->step(this, a);
				ignore[t.x][t.y] = true;
			}
		}
	}
}

int level::getRandomChamber() const{
	return rand()%(chmbrs.size());
}

void level::add(obj *toAdd, const coord &pos){
	if(grd[pos.x][pos.y] == nullptr){
		grd[pos.x][pos.y] = toAdd;
	}else{
		delete toAdd;
	}
}

void level::replace(obj *toAdd, const coord &pos){
	delete grd[pos.x][pos.y];
	grd[pos.x][pos.y] = toAdd;
}


void level::update(obj *toAdd, const coord &pos){
	grd[pos.x][pos.y] = toAdd;
}

bool level::move(const coord &origin, const coord &target){
	if(empty(target)){
		grd[target.x][target.y] = grd[origin.x][origin.y];
		grd[origin.x][origin.y] = nullptr;
		grd[target.x][target.y]->chngPos(target);
		return true;
	}
	return false;
}

//Gets the character of the object at coordinate c
void level::render(std::ostream &out, player *const p, const int gld, bool extra) const{
	td->render(out, p, gld, extra);
}

void level::render(std::ostream &out) const{
	td->render(out);
}

level::~level(){
	for(int i = 0;i < 79;i++){
		for(int j = 0;j < 30;j++){
			delete grd[i][j];
			grd[i][j]=nullptr;
		}
	}

	for (auto it = chmbrs.begin() ; it != chmbrs.end(); ++it) {
	 delete (*it);
   }
	delete td;
}

void level::remove(const coord &c){
	delete grd[c.x][c.y]; //if it's nullptr this is still fine
	grd[c.x][c.y]=nullptr; //avoid segfault
}

level::Walk level::canWalk(const coord &c) const{
	return can[c.x][c.y];
}

int level::getFloorNum() const{
	return floorNum;
}

//Checks if an enemy can move to specified coordinate
bool level::enemyStuck(const coord &c){
	return !(empty(c)) || !(canWalk(c)==level::All);
}

//Checks if an enemy can more to any adjacent coordinate
bool level::enemyTrapped(const coord &c){
	return (   	enemyStuck(coord{c.x,c.y+1}) &&
				enemyStuck(coord{c.x+1,c.y+1}) &&
				enemyStuck(coord{c.x-1,c.y+1}) &&
				enemyStuck(coord{c.x+1,c.y-1}) &&
				enemyStuck(coord{c.x,c.y-1})   &&
				enemyStuck(coord{c.x-1,c.y-1}) &&
				enemyStuck(coord{c.x-1,c.y})   &&
				enemyStuck(coord{c.x+1,c.y}));
}


chamber* level::getChmbr(const int a) const {
	return chmbrs[a];
}

obj *level::getObj(const coord &c) const{
	return grd[c.x][c.y];
}

//Returns the player character object
character* level::getPC() const{
	for(int i = 0;i < 30;i++){
		for(int j = 0;j < 79;j++){
			if(!empty(coord(j, i)) && getObj(coord(j, i))->render() == '@'){
				return static_cast<character*> (getObj(coord(j,i)));
			}
		}
	}
	return nullptr;

}


bool level::close(const obj  *const obs, const obj  *const subj ) const{
	for(int i = 0;i < 30;i++){
		for(int j = 0;j < 79;j++){
			if(!empty(coord(j, i)) && getObj(coord(j, i))==subj){
				return (abs(j - obs->getPos().x) <= 1 && abs(i - obs->getPos().y) <= 1);
			}
		}
	}
	return false;
}
