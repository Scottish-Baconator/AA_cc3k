/*
 * grid.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef FLOOR_H_
#define FLOOR_H_
#include "obj.h"
#include "chamber.h"
#include "player.h"
#include <iostream>

class textDisplay;
class action;

class level{
	int floorNum;
	textDisplay *td = nullptr;
	obj* grd[79][30];
	chamber *chmbrs[5];
public:
	enum Walk {All, PC, No};
private:
	Walk can[79][30];
	void randGen();
	void setWalk();
public:

	level(std::string file, action *a, int floorNum, bool rand);

	~level();

	chamber* getChmbr(int a){return chmbrs[a];}
	void add(obj *toAdd, coord pos);
	void replace(obj *toAdd, coord pos);
	void render(std::ostream &out, player *p, int gld);
	void step(action *a);
	obj *getObj(coord c){return grd[c.x][c.y];}
	bool empty(coord c);
	bool move(coord origin, coord target);
	Walk canWalk(coord c);
	void remove(coord c);
	void update(obj *toAdd, coord pos);
	int getFloorNum();
	bool enemyStuck(coord c);
	bool enemyTrapped(coord c);
};



#endif /* FLOOR_H_ */
