/*
 * character.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */
#include "character.h"
#include <cstdlib>

character::character(coord pos, int hp, int atk, int def): obj{pos},mhp{hp},hp{hp},atk{atk},def{def}{}

void character::attack(character *subj){
	int dmg;
	if(rand() % 100 < subj->dodgeChance()){
		dmg = 0;
	}else {
		dmg = ceil((100/(100+subj->getDef()))*(this->getAtk()));
		dmg = atkEffect(subj, dmg);
		subj->chngHP(-dmg);
	}
}

//both players and enemies can have an atkEffect (vampire; elf)
//by default, it does nothing and just returns the damage.
int character::atkEffect(character *subj, int dmg){
	(void)subj; //avoids unused parameter warning
	return dmg;
}

void character::chngHP(int change){
	hp += change;

	if(hp>mhp && !ignoreMHP()){
		hp = mhp;
	}else if(hp<0){
		hp = 0;
	}
}

int character::getHP(){
	return hp;
}
int character::getAtk(){
	return atk;
}
int character::getDef(){
	return def;
}

//By default, enemies never dodge
int character::dodgeChance(){
	return 0;
}

//Special Effect Flags
//Drain returns the health drain of a vamp
	//Overriden by dwarf to -5
int character::drain(){
	return 5;
}

//Allows vampire to not have max hp. This flag lets us generalize
bool character::ignoreMHP(){
	return false;
}

//Allows troll to regenerate HP
int character::regen(){
	return 0;
}

//Allows goblin to steal items
int character::steal(){
	return 0;
}

//Used by drow to double-attack most player races
bool character::canDouble(){
	return false;
}

//Used by orcs do deal extra damage to goblins
bool character::orcWeakness(){
	return false;
}



