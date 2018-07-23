/*
 * grid.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef FLOOR_H_
#define FLOOR_H_
#include "obj.h"
#include "chamber.h"
#include "player.h"
#include <iostream>
#include <vector>

class textDisplay;
class action;

class level{
	int floorNum;
	textDisplay *td = nullptr;
	std::vector<std::vector<obj*>> grd;
	chamber *chmbrs[5];
public:
	enum Walk {All, PC, No};

private:
	Walk can[79][30];
	void randGen();
	void setWalk();
	void makeChambers();

public:

	level(std::string file, action *a, int floorNum, bool rand);

	~level();

	chamber* getChmbr(const int a) const;
	int getFloorNum() const;
	obj *getObj(const coord &c) const;

	void add(obj *toAdd, const coord &pos);
	void replace(obj *toAdd, const coord &pos);
	void remove(const coord &c);
	void update(obj *toAdd, const coord &pos);

	void render(std::ostream &out, player *const p, const int gld) const;
	void step(action *a);
	bool move(const coord &origin, const coord &target);

	bool empty(const coord &c) const;
	Walk canWalk(const coord &c) const;

	//True if an enemy cannot move to c (not empty or not walkable)
	bool enemyStuck(const coord &c);

	//Checks enemyStuck all 8 directions
	bool enemyTrapped(const coord &c);
};



#endif /* FLOOR_H_ */
