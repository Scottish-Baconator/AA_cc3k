/*
 * enemy.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */
#include "enemy.h"
#include <cmath>

int abs(int a){
	return (a < 0 ? -a : a);
}

bool closePC(level *f, coord c){
	for(int i = 0;i < 30;i++){
		for(int j = 0;j < 79;j++){
			if(f->getObj(coord(j, i))->render() == '@'){
				return (abs(j - c.x) <= 1 && abs(i - c.y) <= 1);
			}
		}
	}
	return false;
}

character* getPC(level *f){
	for(int i = 0;i < 30;i++){
		for(int j = 0;j < 79;j++){
				if(f->getObj(coord(j, i))->render() == '@'){
					return f->getObj(coord(j,i));
			}
		}
	}
	return nullptr;

}

void enemy::attack(character *toAtk){
	if(rand()%2 == 0){
		return;
	}
	this->atkEffect(toAtk);
	toAtk->chngHP(-ceil((100/(100+toAtk->getDef()))*(this->getAtk())));
}

void move(level *f, coord pos){
	coord to(pos);
	bool done = false;
	int count = 0;
	do{
		to = pos;
		switch(rand()%8){
		case 0:
			to.x++;
			break;
		case 1:
			to.x++;to.y++;
			break;
		case 2:
			to.y++;
			break;
		case 3:
			to.x--;to.y++;
			break;
		case 4:
			to.x--;
			break;
		case 5:
			to.x--;to.y--;
			break;
		case 6:
			to.y++;
			break;
		case 7:
			to.x++;to.y--;
		}

	}while((!(f->canWalk(to) == level::All))||(count > 20));
	f->move(pos, to);
}

void enemy::step(level *f){
	if(closePC(f, pos)){
		attack(getPC(f));
	}else{
		move(f, pos);
	}
}
