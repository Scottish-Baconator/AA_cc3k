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
	int HP;
	int Atk, Def;
public:
	char render(){
		return '@';
	}
	virtual int getAtk();
	virtual int getDef();
};



#endif /* PLAYER_H_ */
