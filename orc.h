/*
 * orc.h
 *
 *  Created on: Jul 13, 2018
 *      Author: ajsme
 */

#ifndef ORC_H_
#define ORC_H_

#include "enemy.h"

class orc: public enemy{
	public:
		orc(coord pos); //calls enemy constructor with required params

		char render() override;

		int atkEffect(character *subj, int dmg) override;
};

#endif /* ORC_H_ */
