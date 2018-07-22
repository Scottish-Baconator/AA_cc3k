/*
 * game.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef GAME_H_
#define GAME_H_
#include <string>
#include "coord.h"

const static int MAX_FLOORS = 5;

class level;
class player;
class action;

class game{
	bool provided;
	bool done;
	int floorNum;//starts from 1
	std::string file;
	action *a;
	level *f;
	player *p = nullptr;
	player *pp = nullptr;//potioned player
	coord pC = coord(0,0);
	coord stairs = coord (10, 10);
	int gld;
	bool paused;
	void nextLevel();
	char racePick();
	char race = 'I';
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
	char getRace();
	bool goodRace();
	bool isDone();
	int getGold();
	int getHP();
	~game(){};
};



#endif /* GAME_H_ */
