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
	int HP, MHP;
	int Atk, Def;
public:
	player(int h, int a, int d);
	char render(){
		return '@';
	}
	void chngHP(int p);
	int getHP()	{return HP;}
	int getAtk(){return Atk;}
	int getDef(){return Def;}
};



#endif /* PLAYER_H_ */
