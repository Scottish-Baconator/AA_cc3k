/*
 * action.h
 *
 *  Created on: Jul 17, 2018
 *      Author: ajsme
 */

#ifndef ACTION_H_
#define ACTION_H_
#include <string>

class action {
	std::string text="Player Character has spawned";

public:
	void clear();
	void addText(std::string txt);
	std::string printText();
};




#endif /* ACTION_H_ */
