/*
 * textdisplay.cc
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */
#include "textdisplay.h"
#include "floor.h"
#include "player.h"
#include "obj.h"
#include <iostream>

textDisplay::textDisplay(std::string file, level *f):f{f}{
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

void textDisplay::render(std::ostream &out, player *p){

	//Renders the map
	coord c = coord(0,0);
	for(c.y=0;c.y < 25;(c.y)++){
		for(c.x = 0;c.x < 79;(c.x)++){
			if(f->empty(c)){
				out << map[c.x][c.y];
			}else {
				out << (f->getObj(c))->render();
			}
		}
		out<<'\n';
	}

	out << "Race: " << p->getName();
	out << "Gold: 0";
	out << "Floor: 1" << std::endl;
	out << "HP: " << p->getHP() << std::endl;
	out << "ATK: " << p->getAtk() << std::endl;
	out << "DEF: " << p->getDef() << std::endl;
	out << "Action: " << std::endl;

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


