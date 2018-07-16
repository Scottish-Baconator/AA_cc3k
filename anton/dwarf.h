/*
 * dwarf.h
 *
 *  Created on: Jul 13, 2018
 *      Author: ajsme
 */

#ifndef DWARF_H_
#define DWARF_H_


#include "enemy.h"

class dwarf: public enemy{
public:
	dwarf(coord pos); //calls enemy constructor with required params

	char render() override;

	//overrides to a negative drain
	int drain() override;
};



#endif /* DWARF_H_ */
