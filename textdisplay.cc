/*
 * textdisplay.cc
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */
#include "textdisplay.h"

textDisplay::textDisplay(std::string file){
	std::ifstream in;
	in.open(file);
	for(int i = 0;i < 30;i++){
		for(int j = 0;j < 79;j++){
			in >> map[j][i];
			//map[j][i] << in.peek();
			//in.ignore();
		}
	//	in.ignore();
	}
}

char textDisplay::render(coord c){
	return map[c.x][c.y];
}

void textDisplay::chambFrom(coord c, chamber *ch){
	ch->addCoord(c);
	if(map[c.x][c.y] != '.' || (ch->containsCoord(c))){
		return;
	}
	if(c.x > 0){
		chambFrom(coord(c.x - 1, c.y), ch);
		if(c.y > 0){
			chambFrom(coord(c.x - 1, c.y - 1), ch);
		}
		if(c.y < 29){
			chambFrom(coord(c.x - 1, c.y + 1), ch);
		}
	}
	if(c.x < 78){
		chambFrom(coord(c.x + 1, c.y), ch);
		if(c.y > 0){
			chambFrom(coord(c.x + 1, c.y - 1), ch);
		}
		if(c.y < 29){
			chambFrom(coord(c.x + 1, c.y + 1), ch);
		}
	}
	if(c.y > 0){
		chambFrom(coord(c.x, c.y - 1), ch);
	}
	if(c.y < 29){
		chambFrom(coord(c.x, c.y + 1), ch);
	}
}


