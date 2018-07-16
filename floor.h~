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
#include "textDisplay.h"

class level{
	textDisplay *td = nullptr;
	obj* grd[30][79];
	chamber *chmbrs[5];
public:
	enum Walk {All, PC, No};
private:
	Walk can[30][79];
public:
	level(std::string);

	//floor(std::string file, bool);
	//For later implementation

	~level();

	void add(obj* toAdd, coord pos);
	char render(coord);
	void step();
	obj *getObj(coord c){return grd[c.x][c.y];}
	bool move(coord from, coord to);
	Walk canWalk(coord c){return can[c.x][c.y];}
};



#endif /* FLOOR_H_ */
