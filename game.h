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

class game{
	level f;

public:
	game(bool);
	game(std::string, bool);
	enum dir {no, so, ea, we, ne, nw, se, sw};
	bool move(enum dir d);
	bool use(enum dir d);
	bool attack(enum dir d);
	void stop();
	void restart();
	void render(std::iostream &out);
	void race(char r);
	~game();
};



#endif /* GAME_H_ */
