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
const static int CHAR_IN_FLOOR = 2000;

class level;
class player;
class action;
class obj;

class game{
	bool randomize;
	bool extra;
	obj* tHoard=nullptr;
	bool bHoard=false;
	bool done=false;
	int floorNum=1;//starts from 1
	std::string file;
	action *a;
	level *f;
	player *p = nullptr;
	player *pp = nullptr;//potioned player
	coord pC = coord(0,0);
	int gld=0;
	bool paused=false;
	void nextLevel();
	char racePick();
	char race = 'I';
public:
	game(std::string);
	game(std::string, bool random, bool extra);
	enum dir {no, so, ea, we, ne, nw, se, sw};
	bool move(dir d);
	bool use(dir d);
	bool attack(dir d);
	void stop();
	void step();
	void render(std::ostream &out);
	std::string getRace();
	bool goodRace();
	bool isDone();
	bool isWinner();
	int getScore();
	~game();
	void gotoNext();
};



#endif /* GAME_H_ */
