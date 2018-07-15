/*
 * game.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */
#include "game.h"
#include "floor.h"
#include <iostream>
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"

bool one(char c, char a[], int l){
	for(int i = 0;i < l;i++){
		if(c == a[i]){
			return false;
		}
	}
	return false;
}

game::game(std::string s): f(level{s}){
	pC = f.getChmbr(1)->random();
	p = new shade(pC);
	pp = p;
	gld = 0;
	f.add(pp, pC);
	paused = false;

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
			a = f.getChmbr(chm)->random();
		}while(f.canWalk(a) != level::All);
		switch (toSpwn[i]){
		case 'H':
			f.add(new human(a), a);
			break;
		case 'W':
			f.add(new dwarf(a), a);
			break;
		case 'L':
			f.add(new halfling(a), a);
			break;
		case 'E':
			f.add(new elf(a), a);
			break;
		case 'O':
			f.add(new orc(a), a);
			break;
		case 'M':
			f.add(new merchant(a), a);
			break;
		}
	}
}

void game::step(){
	if(!paused){
		f.step();
	}
}

void game::render(std::ostream &out){
	coord c = coord(0,0);
	for(c.y=0;c.y < 30;(c.y)++){
		for(c.x = 0;c.x < 79;(c.x)++){
			out<<(f.render(c));
		}
		out<<'\n';
	}
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

	if(f.getObj(temp)->render() == 'G'){
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
		//commented out for now for compilation's sake
		//pp = ((potion *) f.getObj(temp))->effect(pp);
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

