/*
 * hoard.h
 *
 *  Created on: Jul 13, 2018
 *      Author: ajsme
 */

#ifndef HOARD_H_
#define HOARD_H_

#include "gold.h"
#include "floor.h"

class dragon;

class hoard: public gold{
public:
	hoard(coord pos, level *f);
	hoard(coord pos, level *f, coord dragonPos);

	void unprotectHoard(); //Called by dragon when dragon dies

	//Note: Hoard does not need to store a pointer to the dragon it created.
	//When the dragon dies, it will unlock the hoard by itself. The hoard doesn't actually care
	//about the dragon. ie Dragon HAS A Horde, not vice versa.
};





#endif /* HOARD_H_ */
