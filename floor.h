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
	enum Walk {All, PC, No};
	textDisplay *td = nullptr;
	Walk can[][] = nullptr;
	obj* grd[][] = nullptr;
	chamber *chmbrs = nullptr;
public:
	level(std::string);

	//floor(std::string file, bool);
	//For later implementation

	~level();

	void add(obj* toAdd, coord pos);
	void render();
	void step();
	obj *getObj(coord c){return grd[c.x][c.y];}
	void move(coord from, coord to);
	Walk canWalk(coord c){return can[c.x][c.y];}
};



#endif /* FLOOR_H_ */
