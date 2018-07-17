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
	void addText(std::string txt);
	std::string intToString(int n);

public:
	void clear();
	std::string printText();
	void movePC(std::string dir);
	void addGold(int gldAmt);

	void cantMove(std::string dir);

	void attack(std::string attacker, std::string defender, int dmg);

	void showHP(std::string subject, int hp);
	void miss(std::string attacker, std::string defender);
};




#endif /* ACTION_H_ */
