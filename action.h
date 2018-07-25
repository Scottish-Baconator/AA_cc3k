/*
 * action.h
 *
 *  Created on: Jul 17, 2018
 *      Author: ajsme
 */

#ifndef ACTION_H_
#define ACTION_H_
#include <string>

//The action class is used to display the "action text" seen at the bottom of the display
//Classes call action's methods to add text, all of which are managed in the action class itself
//so it is easily accessible and changeable.
class action {
	std::string text="Player Character has spawned";
	void addText(std::string txt);
	std::string intToString(int n);

public:
	void clear();
	std::string printText();

	//Called when the PC moves in the given direction
	void movePC(std::string dir);

	//Called when the PC picks up gold.
	void addGold(int gldAmt);

	//Called when the player tries to move where they cannot
	void cantMove(std::string dir);

	//Called when one character attacks another
	void attack(std::string attacker, std::string defender, int dmg);

	//Called when the player defeats the named enemy
	void slay(std::string name);

	//Displays the HP of the enemy
	void showHP(std::string subject, int hp);

	//Called when an attack misses
	void miss(std::string attacker, std::string defender);

	//Called when the PC uses a potion
	void usePot(std::string name);

	//Called when PC uses armour
	void addArmour(int val);

	//Called when the PC's stat changes
	void changeStat(std::string statname, std::string change, int amt);
};




#endif /* ACTION_H_ */
