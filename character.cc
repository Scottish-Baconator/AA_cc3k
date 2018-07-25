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

character::~character(){}

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
			dmg -= subj->armour();
			subj->chngHP(-dmg);
			a->attack(getName(), subj->getName(), dmg);
		}
	}
}

//by default, no effect and just returns the damage.
int character::atkEffect(character *const subj, const int dmg){
	(void)subj; //avoids unused parameter warning
	return dmg;
}

void character::chngHP(const int change){
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

int character::getHP() const{
	return hp;
}
double character::getAtk() const{
	return atk;
}
double character::getDef() const{
	return def;
}
std::string character::getName() const{
	return name;
}

//By default, enemies never dodge
int character::dodgeChance() const{
	return 0;
}

int character::drain() const{
	return 5;
}

bool character::doubleAttack() const{
	return false;
}
bool character::canSteal() const{
	return false;
}

//Allows vampire to not have max hp. This flag lets us generalize
bool character::ignoreMHP() const{
	return false;
}

double character::potionMulti() const{
	return 1;
}

//Allows troll to regenerate HP
int character::regen() const{
	return 0;
}

//Allows goblin to steal gold. Default is 5
int character::stealAmt() const{
	return 5;
}

//Used by drow to double-attack most player races
bool character::canDouble() const{
	return true;
}

//Used by orcs do deal extra damage to goblins
bool character::smallWeakness() const{
	return false;
}

int character::armour() const{
	return 0;
}


