/*
 * coord.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef COORD_H_
#define COORD_H_


struct coord{
	int x, y;
	coord(int a, int b): x(a), y(b){}

	bool eq(const coord &a) const{
		return (a.x == x && a.y == y);
	}
};


#endif /* COORD_H_ */
