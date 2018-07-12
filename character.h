/*
 * character.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "obj.h"

class character: public obj{
public:
	virtual ~character(){};
	virtual void attack(character subj){};
	virtual void step();
};



#endif /* CHARACTER_H_ */
