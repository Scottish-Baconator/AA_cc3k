/*
 * enemy.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */
#include "enemy.h"
#include "floor.h"
#include "gold.h"
#include <iostream>


//Move to a random neighbouring tile
coord enemy::move(level *f){
	coord to(pos);
	int guard;

	if(f->enemyTrapped(pos))
		{
		return pos;
	}

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
				break;
			default:
				return pos;
		}
		++guard;
		if(guard>50){
			return pos;
		}

	}while(f->enemyStuck(to));
	f->move(pos, to);
	return to;
}

enemy::enemy(coord pos, int hp, double atk, double def, std::string name, bool hostile, bool stationary):
		character(pos, hp, atk, def, name),isHostile{hostile},isStationary{stationary}

{}

enemy::~enemy(){}

//Runs enemy action.
coord enemy::step(level *f, action *a){
	if(closePC(f) && isHostile){
		attack(f->getPC(), a);
	}else if(!isStationary){
		pos = move(f);
	}
	return pos;
}

//Spawns a gold of the specified val adjacent to pos on the given level
void enemy::spawn(level *f, const coord &pos, int val){
	coord to(pos);

	if(!f->enemyTrapped(pos)){
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

		}while(f->enemyStuck(to));
		f->add(new gold(to, val),to);
	}
}


//By default, enemies drop small or normal gold on their position
void enemy::drop(level *f){
	f->replace(new gold(pos, (rand()%2)*2),pos);
}


bool enemy::closePC(level *const f) const{
	return f->close(this,f->getPC());
}
