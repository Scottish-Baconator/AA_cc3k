/*
 * player.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "character.h"

class player: public character{
	int MHP;
	int Atk, Def;
public:
	player(int h, int a, int d, coord pos);
	char render(){
		return '@';
	}
	void chngHP(int p);
	int getAtk(){return Atk;}
	int getDef(){return Def;}
};



#endif /* PLAYER_H_ */
