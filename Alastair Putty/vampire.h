/*
 * vampire.h
 *
 *  Created on: Jul 13, 2018
 *      Author: ajsme
 */

#ifndef VAMPIRE_H_
#define VAMPIRE_H_



#include "player.h"

class vampire: public player{
public:
	vampire(coord pos);

	//void chngHP(int p);

	int atkEffect(character *const subj, int dmg) override;

	//Allows vampire to not have max hp
	bool ignoreMHP() const override;
};




#endif /* VAMPIRE_H_ */
