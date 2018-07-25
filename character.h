/*
 * character.h
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "obj.h"
#include <cmath>
#include <string>

class action;

//Abstract class that encompasses players and enemies
//Handles most of the combat-related mechanics
class character: public obj{
	int mhp, hp;
	double atk, def;
	std::string name;

public:
	character(coord pos, int hp, double atk, double def, std::string name);

	virtual ~character();

	//Attack does not get overriden so resolving combat stays generalized
	//Enemies and players both call this same attack command when attacking the subject
	void attack(character *subj, action *a);
	
	//Both players and enemies can have an atkEffect (vampire; elf)
	virtual int atkEffect(character *const subj, const int dmg);
	
	virtual char render() const=0;

	//Changes HP by the given amount. Cannot exceed MHP unless the given flag is true
	void chngHP(const int change);

	//Used when a character gets attacked. Ex. When merchant gets attacked, they become hostile.
	virtual void attacked();

	//Accessors
	int getHP() const;
	virtual double getAtk() const;
	virtual double getDef() const;
	std::string getName() const;
	
	//By default, enemies never dodge
	virtual int dodgeChance() const;


	//Special Effect Flags
	//These get overriden by classes that use the effects

	//Drain returns the health drain of a vamp
		//Overriden by dwarf to -5
	virtual int drain() const;

	//Allows character to attack twice
	virtual bool doubleAttack() const;

	//Steals upon killing an enemy
	virtual bool canSteal() const;

	//Multiplier to change potion effectiveness
	virtual double potionMulti() const;

	//Allows vampire to not have max HP.
	virtual bool ignoreMHP() const;
	
	//Allows troll to regenerate HP
	virtual int regen() const;

	//Allows goblin to steal items
	virtual int stealAmt() const;

	//Used by drow to double-attack most player races
	virtual bool canDouble() const;

	//Used by orcs do deal extra damage to goblins (small creatures)
	virtual bool smallWeakness() const;

	virtual int armour() const;

	void setHP(int h){
		hp = h;
	}
};



#endif /* CHARACTER_H_ */
