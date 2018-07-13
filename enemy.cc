/*
 * enemy.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */
#include "enemy.h"
#include <cmath>

//abs already included somewhere else (cmath?)
/*int abs(int a){
	return (a < 0 ? -a : a);
}*/

//Determines if the player is on a neighbouring tile
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

//Finds the player character object
character* getPC(level *f){
	for(int i = 0;i < 30;i++){
		for(int j = 0;j < 79;j++){
			if(f->getObj(coord(j, i))->render() == '@'){
				return (character*) f->getObj(coord(j,i));
			}
		}
	}
	return nullptr;

}

//Move to a random neighbouring tile
void move(level *f, coord pos){
	coord to(pos);
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

enemy::enemy(coord pos, int hp, int atk, int def, bool hostile, bool stationary):
		character(pos, hp, atk, def),isHostile{hostile},isStationary{stationary}

{}

enemy::~enemy(){}

//Runs enemy action.
void enemy::step(level *f){
	if(closePC(f, pos) && isHostile){
		attack(getPC(f));
	}else if(!isStationary){
		move(f, pos);
	}
}

//By default, enemies dont drop anything
void enemy::drop(level *f){
	(void)f;
}
