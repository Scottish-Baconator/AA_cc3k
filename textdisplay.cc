/*
 * textdisplay.cc
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */
#include "textdisplay.h"
#include <iostream>
textDisplay::textDisplay(std::string file){
	std::ifstream in;
	in.open(file);
	char c='.';

	for(int i = 0;i < 30;i++){
		for(int j = 0;j < 79;j++){
			in.get(c);
			map[j][i] = c;
			//map[j][i] << in.peek();
			//in.ignore();
		}
		//ignores whitespace
		in.ignore();
	}
}

char textDisplay::render(coord c){
	return map[c.x][c.y];
}

void textDisplay::chambFrom(coord c, chamber *ch){
	/*(void)c;*/
	//(void)ch;

	if(c.x<0 || c.x>=79 || c.y<0 || c.y>=30 || map[c.x][c.y] != '.' || ch->containsCoord(c)){
		return;
	}

	ch->addCoord(c);

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


