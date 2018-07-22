/*
 * textdisplay.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef TEXTDISPLAY_H_
#define TEXTDISPLAY_H_
#include "chamber.h"
#include "player.h"
#include <string>
#include <fstream>
#include <iostream>

class player;
class action;

//class declaration to prevent circular include
class level;

class textDisplay {
	level *f;
	action *a;
	char map[79][30];
	obj* type(char c, coord pos);
public:
	textDisplay(std::string file, level *f, action *a, bool rand);
	void render(std::ostream &out, player *p, int gld);
	void chambFrom(coord c, chamber *ch);
	char get(coord c){return map[c.x][c.y];}
};


#endif /* TEXTDISPLAY_H_ */
