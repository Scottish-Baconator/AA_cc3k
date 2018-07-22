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
#include "action.h"
#include "potion.h"
#include "gold.h"
#include "hoard.h"
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include <iostream>
#include <string>
#include <vector>

bool isIn(char a, char b[], int len){
	for(int i = 0;i < len;i++){
		if(a == b[i]){
			return true;
		}
	}
	return false;
}

obj* textDisplay::type(char c, coord pos, std::vector<coord> drgns){
	coord d = drgns.front();
	switch(c){
	case '0':
		return new potion(pos, potion::RH);
	case '1':
		return new potion(pos, potion::BA);
	case '2':
		return new potion(pos, potion::BD);
	case '3':
		return new potion(pos, potion::PH);
	case '4':
		return new potion(pos, potion::WA);
	case '5':
		return new potion(pos, potion::WD);
	case '6':
		return new gold(pos, 2);
	case '7':
		return new gold(pos, 1);
	case '8':
		return new gold(pos, 4);
	case '9':
		drgns.erase(drgns.begin());
		return new hoard(pos, f, d);
	case 'M':
		return new merchant(pos);
	case 'E':
		return new elf(pos);
	case 'H':
		return new human(pos);
	case 'W':
		return new dwarf(pos);
	case 'O':
		return new orc(pos);
	case 'L':
		return new halfling(pos);
	}
	return nullptr;
}

textDisplay::textDisplay(std::string file, level *f, action *a, bool rand):f{f},a{a}{
	std::ifstream in;
	std::ifstream dr;
	std::vector<coord> dragons;
	char accept[] = {'|', '-', '.', '#', '+', ' '};
	int aLen = 6;
	dr.open(file);
	char c='.';
	if(!rand){
		for(int i = 0;i < 25;i++){
			for(int j = 0;j < 79;j++){
				dr.get(c);
				if((!rand) && c == 'D'){
					coord ta{j, i};
					dragons.push_back(ta);
				}
			}
		}
	}
	in.open(file);
	for(int i = 0;i < 25;i++){
		for(int j = 0;j < 79;j++){
			in.get(c);

			if((!rand) && !isIn(c, accept, aLen)){
				map[i][j] = '.';
				coord pos{j, i};
				f->add(type(c, pos, dragons), pos);
			}else{
				map[j][i] = c;
			}
			//map[j][i] << in.peek();
			//in.ignore();
		}
		//ignores whitespace
		in.ignore();
	}
}

void textDisplay::render(std::ostream &out, player *p, int gld){

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
		out << '\n';
	}

	out << "Race: " << p->getRace() << "\t";
	out << "Gold: " << gld << "\t";
	out << "Floor: " << f->getFloorNum() << std::endl;
	out << "HP: " << p->getHP() << std::endl;
	out << "ATK: " << p->getAtk() << std::endl;
	out << "DEF: " << p->getDef() << std::endl;
	out << "Action: " <<  a->printText() << std::endl;

}

void textDisplay::chambFrom(coord c, chamber *ch){
	if(c.x < 0 || c.x >= 79 || c.y < 0 || c.y >= 30 || map[c.x][c.y] != '.' || ch->containsCoord(c)){
		return;
	}
	if(map[c.x][c.y] == '.'){
		ch->addCoord(c);
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

