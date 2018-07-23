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
#include <vector>

class player;
class action;

//class declaration to prevent circular include
class level;

class textDisplay {
	level *f;
	action *a;
	std::vector<std::vector<char>> map;
	obj* type(char c, coord pos, std::vector<coord> dragons);
public:
	textDisplay(std::string file, level *f, action *a, bool rand);
	void render(std::ostream &out, player *const p, const int gld) const;
	void chambFrom(coord c, chamber *ch);
	char get(const coord &c) const;
};


#endif /* TEXTDISPLAY_H_ */
