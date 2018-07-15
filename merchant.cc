/*
 * merchant.cc
 *
 *  Created on: Jul 15, 2018
 *      Author: alicy
 */

#include "merchant.h"

merchant::merchant(coord pos): enemy(pos, 30, 70, 5, "merchant", false, false){
	merchantInit();
}

char merchant::render(){
	return 'M';
}
