/*
 * game.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef GAME_H_
#define GAME_H_
#include "floor.h"
#include <iostream>
#include <string>
#include "potion.h"
#include "shade.h"
#include "enemy.h"
#include "gold.h"

class action;

class game{
	std::string file;
	action *a;
	level f;
	player *p = nullptr;
	player *pp = nullptr;//potioned player
	coord pC = coord(0,0);
	coord stairs = coord (10, 10);
	int gld;
	bool paused;
	void nextLevel();
public:
	game(std::string);
	game(std::string, bool);
	enum dir {no, so, ea, we, ne, nw, se, sw};
	bool move(dir d);
	bool use(dir d);
	bool attack(dir d);
	void stop();
	void step();
	void render(std::ostream &out);
	void race(char r);
	~game(){};
};



#endif /* GAME_H_ */
