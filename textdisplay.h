/*
 * textdisplay.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef TEXTDISPLAY_H_
#define TEXTDISPLAY_H_
#include "chamber.h"
#include <string>
#include <fstream>

class textDisplay {
	char map[79][30];
public:
	textDisplay(std::string file);
	~textDisplay(){}
	char render(coord c);
	void chambFrom(coord c, chamber *ch);
	char get(coord c){return map[c.x][c.y];}
};


#endif /* TEXTDISPLAY_H_ */
