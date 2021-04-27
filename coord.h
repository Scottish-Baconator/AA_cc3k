/*
 * coord.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef COORD_H_
#define COORD_H_
#include <iostream>

struct coord{
	int x, y;
	coord(int a, int b): x(a), y(b){}

	bool eq(const coord &a) const{
		return (a.x == x && a.y == y);
	}

	friend std::ostream &operator<<(std::ostream &out, coord c){
		out<<"("<<c.x<<", "<<c.y<<")";
		return out;
	}
};


#endif /* COORD_H_ */
