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
#include "textdisplay.h"

class level{
	textDisplay *td = nullptr;
	obj* grd[79][30];
	chamber *chmbrs[5];
public:
	enum Walk {All, PC, No};
private:
	Walk can[79][30];
public:
	level(std::string);

	//level(std::string file, bool);
	//For later implementation

	~level();

	chamber* getChmbr(int a){return chmbrs[a];}
	void add(obj *toAdd, coord pos);
	char render(coord);
	void step();
	obj *getObj(coord c){return grd[c.x][c.y];}
	bool move(coord from, coord to);
	Walk canWalk(coord c);
	void remove(coord c);
};



#endif /* FLOOR_H_ */
