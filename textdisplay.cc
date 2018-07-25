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
#include "dragon.h"
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "bugbear.h"
#include <iostream>
#include <string>
#include <vector>

bool close(coord a, coord b){
	return ((abs(a.x - b.x) <= 1) && (abs(a.y - b.y) <= 1));
}

coord findNearestDragon(coord c, std::string file){
	std::ifstream in(file);
	char ch = '.';
	coord cur(0,0);
	for(cur.y = 0;cur.y < 25;cur.y++){
		for(cur.x = 0;cur.x < 79;cur.x++){
			in.get(ch);
			if(close(cur, c)){
				if(ch == 'D'){
					return cur;
				}
			}
		}
		in.ignore();
	}
	return coord(0,0);

}

bool isIn(char a, char b[], int len){
	for(int i = 0;i < len;i++){
		if(a == b[i]){
			return true;
		}
	}
	return false;
}

obj* textDisplay::type(char c, coord pos, std::string file){
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
			return new hoard(pos, f, findNearestDragon(pos, file));
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
	map.resize(79);
	for(size_t i = 0;i < map.size();i++){
		map[i].resize(30);
	}
	std::ifstream in(file);
	std::ifstream dr;
	char accept[] = {'|', '-', '.', '#', '+', ' ', 'D', '@', '\\'};
	int aLen = 9;
	char c='.';

	for(int i = 0;i < 25;i++){
		for(int j = 0;j < 79;j++){
			map[j][i] = '.';
		}
	}

	if(!rand){
		in.ignore(2000 * (f->getFloorNum() - 1));
	}

	for(int i = 0;i < 25;i++){

		for(int j = 0;j < 79;j++){
			in.get(c);

			//std::cerr << "("<<static_cast<int>(c)<<")";
			if((!rand) && !isIn(c, accept, aLen)){
				map[j][i] = '.';
				coord pos{j, i};
				obj* tem = type(c, pos, file);
				if(tem == nullptr){
					//std::cout<<"Null ("<<j<<", "<<i<<") "<<c<<"\n";
				}else{
					//std::cout<<tem->render()<<" ("<<j<<", "<<i<<") "<<c<<"\n";
				}
				f->add(tem, pos);
			}else{
				if(c == '@'||c == '\\'||c == 'D'){
					map[j][i] = '.';
				}else{
					map[j][i] = c;
				}
			}
		}

		in.ignore();
		//std::cerr << std::endl;
	}

}

void textDisplay::render(std::ostream &out, player *const p, const int gld, bool extra) const{

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
	out << "HP: " << p->getHP();
	if(extra){
		out<<" + Armour: " << p->armour();
	}
	out << std::endl;
	out << "ATK: " << p->getAtk() << std::endl;
	out << "DEF: " << p->getDef() << std::endl;
	out << "Action: " <<  a->printText() << std::endl;

}

void textDisplay::render(std::ostream &out) const{

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
}

void textDisplay::chambFrom(coord c, chamber *ch){
	if(c.x < 0 || c.x >= 79 || c.y < 0 || c.y >= 30 || map[c.x][c.y] != '.' || ch->containsCoord(c)){
		return;
	}
	if(map[c.x][c.y] == '.'){
		ch->addCoord(c);
	}

	//These don't need individual if statements since the guard at the top catches any bad cases
	chambFrom(coord(c.x - 1, c.y), ch);
	chambFrom(coord(c.x - 1, c.y - 1), ch);
	chambFrom(coord(c.x - 1, c.y + 1), ch);
	chambFrom(coord(c.x + 1, c.y), ch);
	chambFrom(coord(c.x + 1, c.y - 1), ch);
	chambFrom(coord(c.x + 1, c.y + 1), ch);
	chambFrom(coord(c.x, c.y - 1), ch);
	chambFrom(coord(c.x, c.y + 1), ch);
}

char textDisplay::get(const coord &c) const{
	return map[c.x][c.y];
}

