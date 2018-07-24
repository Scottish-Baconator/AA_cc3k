/*
 * dragon.h
 *
 *  Created on: Jul 13, 2018
 *      Author: ajsme
 */

#ifndef DRAGON_H_
#define DRAGON_H_

#include "hoard.h"
#include "enemy.h"

class dragon: public enemy{
	hoard *treasure;

	public:
		//A dragon is spawned by the hoard (NOT vice versa)
		dragon(coord pos, hoard *treasure);

		char render() const override;

		//Override because player is close enough to attack if they're beside the hoard
		bool closePC(level *const f) const override;

		//Doesn't actually drop to map, but this function will "unlock" the treasure horde
		void drop(level *f) override;
};


#endif /* DRAGON_H_ */
