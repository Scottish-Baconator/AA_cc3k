/*
 * game.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */
#include "game.h"
#include "floor.h"
#include "potion.h"
#include "stair.h"
#include <iostream>
#include <ctime>

bool one(char c, char a[], int l){
	for(int i = 0;i < l;i++){
		if(c == a[i]){
			return false;
		}
	}
	return false;
}

game::game(std::string s): f(level{s}){
	srand(time(nullptr));
	file = s;
	int pCh = rand()%5;
	pC = f.getChmbr(pCh)->random();
	p = new shade(pC);
	pp = p;
	gld = 0;
	f.add(pp, pC);
	paused = false;
	switch(pCh){
	case 0:
		stairs = f.getChmbr(2)->random();
		break;
	case 1:
		stairs = f.getChmbr(4)->random();
		break;
	case 2:
		stairs = f.getChmbr(0)->random();
		break;
	case 3:
		stairs = f.getChmbr(1)->random();
		break;
	case 4:
		stairs = f.getChmbr(3)->random();
	}
	f.add(new stair(stairs), stairs);
}

void game::nextLevel(){
	f = level{file};
	int pCh = rand()%5;
	pC = f.getChmbr(pCh)->random();
	p = new player{*p};
	delete pp;
	pp = p;
	f.add(pp, pC);
	paused = false;
	switch(pCh){
	case 0:
		stairs = f.getChmbr(2)->random();
		break;
	case 1:
		stairs = f.getChmbr(4)->random();
		break;
	case 2:
		stairs = f.getChmbr(0)->random();
		break;
	case 3:
		stairs = f.getChmbr(1)->random();
		break;
	case 4:
		stairs = f.getChmbr(3)->random();
	}
	f.add(new stair(stairs), stairs);
}

void game::step(){
	if(!paused){
		f.step();
	}
}

void game::render(std::ostream &out){
	f.render(out, pp, gld);
}

coord getCoord(enum game::dir d, coord pC){
	coord tr = pC;
	switch (d){
		case game::no:
			tr.y--;
			break;
		case game::so:
			tr.y++;
			break;
		case game::we:
			tr.x--;
			break;
		case game::ea:
			tr.x++;
			break;
		case game::ne:
			tr.y--;tr.x++;
			break;
		case game::nw:
			tr.y--;tr.x--;
			break;
		case game::se:
			tr.y++;tr.x++;
			break;
		case game::sw:
			tr.y++;tr.x--;
			break;
		}
	return tr;
}

//Moves player in direction dir
bool game::move(dir d){
	//temp is the coordinates the player is trying to move in
	coord temp = getCoord(d, pC);

	if(!(f.empty(temp)) && (f.getObj(temp)->render() == '\\')){
		nextLevel();
	}

	//This empty makes it so we dont check the render of an empty tile
	//getObj doesnt work on an empty tile - ill probably add a throw line to that eventually
	if(!f.empty(temp) && f.getObj(temp)->render() == 'G'){
		gld += ((gold *) (f.getObj(temp)))->getVal();
		f.remove(temp);
	}

	//std::cerr<<"pot"<<std::endl;
	if(f.canWalk(temp) == level::All || f.canWalk(temp) == level::PC){
		//std::cerr<<"a"<<std::endl;
		if(f.move(pC, temp)){
			//std::cerr<<"to"<<std::endl;
			pC = temp;
			return true;
		}
	}
	return false;
}

bool game::use(dir d){
	coord temp = getCoord(d, pC);
	if(f.getObj(temp)->render() == 'P'){
		f.remove(pC);
		pp = ((potion *) f.getObj(temp))->effect(pp);
		f.add(pp, pC);
		return true;
	}
	return false;
}

bool game::attack(dir d){
	char enemies[] = {'H','W','E','O','M','D','L'};
	coord temp = getCoord(d, pC);
	if(one(f.getObj(temp)->render(), enemies, 7)){
		enemy* tAtk = (enemy*)f.getObj(temp);
		pp->attack(tAtk);
		if(tAtk->getHP() < 0){
			tAtk->drop(&f);
			f.remove(temp);
		}
		return true;
	}
	return false;
}

void game::stop(){
	paused = !paused;
}

