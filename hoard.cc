/*
 * hoard.cc
 *
 *  Created on: Jul 22, 2018
 *      Author: ajsme
 */

#include "hoard.h"
#include "floor.h"
#include "dragon.h"
#include <iostream>
hoard::hoard(coord pos, level *f):gold{pos,6,false}{
	coord dc(pos);

	do{
		dc = pos;
		switch(rand()%8){
		case 0:
			dc.x++;
			break;
		case 1:
			dc.x++;dc.y++;
			break;
		case 2:
			dc.y++;
			break;
		case 3:
			dc.x--;dc.y++;
			break;
		case 4:
			dc.x--;
			break;
		case 5:
			dc.x--;dc.y--;
			break;
		case 6:
			dc.y++;
			break;
		case 7:
			dc.x++;dc.y--;
		}

	}while(f->enemyStuck(dc));
	f->add(new dragon(dc, this),dc);
}

hoard::hoard(coord pos, level *f, coord dragonPos):gold{pos,6,false}{
	f->add(new dragon(dragonPos, this),dragonPos);
}


void hoard::unprotectHoard(){
	canPick=true;
}
