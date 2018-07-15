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

//class declaration to prevent circular include
class level;

class textDisplay {
	level *f;
	char map[79][30];
public:
	textDisplay(std::string file, level *f);
	~textDisplay(){}
	void render(std::ostream &out, player *p);
	void chambFrom(coord c, chamber *ch);
	char get(coord c){return map[c.x][c.y];}
};


#endif /* TEXTDISPLAY_H_ */
