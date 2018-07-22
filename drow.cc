/*
 * drow.cc
 *
 *  Created on: Jul 20, 2018
 *      Author: alicy
 */
#include "drow.h"
#include "player.h"

drow::drow(coord pos): player(pos, 150, 25, 15, "Drow"){}


double drow::potionMulti(){
	return 1.5;
}
bool drow::canDouble(){
	return false;
}
