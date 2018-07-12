/*
 * grid.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef FLOOR_H_
#define FLOOR_H_
#include "obj.h"
#include "textDisplay.h"

class floor{
	enum Walk {All, PC, No};
	textDisplay *td = nullptr;
	Walk can[][] = nullptr;
	obj* grd[][] = nullptr;
public:
	floor();

	//floor(std::string file);
	//For later implementation

	~floor();

	void render();
	void step();
	obj *getObj(coord c){return grd[c.x][c.y];}
	void move(coord from, coord to);
};



#endif /* FLOOR_H_ */
