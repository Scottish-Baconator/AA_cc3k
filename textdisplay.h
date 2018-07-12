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
	char **map = nullptr;
public:
	textDisplay(std::string file);
	~textDisplay(){
		delete map;
	}
	void chambFrom(coord c, chamber &ch);
};


#endif /* TEXTDISPLAY_H_ */
