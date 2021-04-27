/*
 * bugbear.cc
 *
 *  Created on: Jul 25, 2018
 *      Author: alicy
 */
#include "bugbear.h"

bugbear::bugbear(coord pos): player(pos, 150, 25, 25, "Bugbear"){

}

double bugbear::armour() const{
	return 5;
}

double bugbear::scoreMultiplier() const{
	return 0.75;
}



