/*
 * drow.h
 *
 *  Created on: Jul 13, 2018
 *      Author: ajsme
 */

#ifndef DROW_H_
#define DROW_H_


#include "player.h"

class drow: public player{
public:
	drow(coord pos);

	double potionMulti() const override;
	bool canDouble() const override;
};



#endif /* DROW_H_ */
