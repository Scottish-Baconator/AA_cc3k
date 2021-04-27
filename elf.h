/*
 * elf.h
 *
 *  Created on: Jul 13, 2018
 *      Author: ajsme
 */

#ifndef ELF_H_
#define ELF_H_
#include "enemy.h"

class elf: public enemy{
	public:
		elf(coord pos); //calls enemy constructor with required params

		char render() const override;

		bool doubleAttack() const override;

};

#endif /* ELF_H_ */
