/*
 * character.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */
#include "character.h"
#include "action.h"
#include <cstdlib>

character::character(coord pos, int hp, double atk, double def,std::string name): obj{pos},mhp{hp},hp{hp},atk{atk},def{def},name{name}
{}

void character::attack(character *subj, action *a){
	int dmg;
	int atktimes = (doubleAttack() && subj->canDouble()) ? 2 : 1;

	for(int i=0; i < atktimes; ++ i){
		if(rand() % 100 < subj->dodgeChance()){
			dmg = 0;
			a->miss(getName(), subj->getName());
		}else {
			dmg = ceil((100/(100+subj->getDef()))*(this->getAtk()));
			dmg = atkEffect(subj, dmg);
			subj->chngHP(-dmg);
			a->attack(getName(), subj->getName(), dmg);
		}
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

	if(change<0){
		attacked();
	}
}

void character::attacked(){
}

int character::getHP(){
	return hp;
}
double character::getAtk(){
	return atk;
}
double character::getDef(){
	return def;
}
std::string character::getName(){
	return name;
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

bool character::doubleAttack(){
	return false;
}
bool character::canSteal(){
	return false;
}

//Allows vampire to not have max hp. This flag lets us generalize
bool character::ignoreMHP(){
	return false;
}

double character::potionMulti(){
	return 1;
}

//Allows troll to regenerate HP
int character::regen(){
	return 0;
}

//Allows goblin to steal gold. Default is 5
int character::stealAmt(){
	return 5;
}

//Used by drow to double-attack most player races
bool character::canDouble(){
	return false;
}

//Used by orcs do deal extra damage to goblins
bool character::smallWeakness(){
	return false;
}



