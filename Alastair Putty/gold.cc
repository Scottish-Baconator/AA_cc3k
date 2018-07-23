/*
 * gold.cc
 *
 *  Created on: Jul 13, 2018
 *      Author: alicy
 */

#include "gold.h"



gold::gold(coord pos, int v, bool pickable): item(pos), val(v), canPick{pickable}{
}

char gold::render() const{
	return 'G';
}
int gold::getVal() const{
	return val;
}
bool gold::getPick() const{
	return canPick;
}
