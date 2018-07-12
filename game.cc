/*
 * game.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */
#include "game.h"

void game::render(std::iostream &out){
	coord c = coord(0,0);
	for(;c.y < 30;c.y++){
		for(;c.x < 79;c.x++){
			out<<(f.render(c));
		}
		out<<'\n';
		c.x = 0;
	}
}


