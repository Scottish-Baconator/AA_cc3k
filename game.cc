/*
 * game.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */
#include "game.h"
#include "floor.h"

bool one(char c, char a[], int l){
	for(int i = 0;i < l;i++){
		if(c == a[i]){
			return false;
		}
	}
	return false;
}

game::game(std::string s): f(s){
	f = level(s);
	pC = f.getChmbr(2)->random();
	p = new shade(pC);
	pp = p;
	gld = 0;
	f.add(pp, pC);
	paused = false;
}

void game::step(){
	if(!paused){
		f.step();
	}
}

void game::render(std::ostream &out){
	coord c = coord(0,0);
	for(;c.y < 30;c.y++){
		for(;c.x < 79;c.x++){
			out<<(f.render(c));
		}
		out<<'\n';
		c.x = 0;
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

bool game::move(enum dir d){
	coord temp = getCoord(d, pC);
	if(f.getObj(temp)->render() == 'G'){
		gld += ((gold *) (f.getObj(temp)))->getVal();
		f.remove(temp);
	}
	if(f.canWalk(temp) == level::All){
		f.move(pC, temp);
		pC = temp;
		return true;
	}
	return false;
}

bool game::use(enum dir d){
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

bool game::attack(enum dir d){
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

