/*
 * action.cc
 *
 *  Created on: Jul 17, 2018
 *      Author: ajsme
 */

#include "action.h"
#include <iostream>
#include <string>
#include <sstream>

void action::clear(){
	text="";
}

void action::addText(std::string txt){
	text += text=="" ? txt : " "+txt;
}

std::string action::printText(){
	std::string print = text;
	clear();
	return print;
}

std::string action::intToString(int n){
	std::ostringstream out;
	out << n;
	return out.str();
}

void action::addGold(int gldAmt){
	addText("PC picks up "+intToString(gldAmt)+" gold.");
}

void action::movePC(std::string dir){
	addText("PC moves "+dir+".");
}

void action::cantMove(std::string dir){
	addText("Can't move "+dir+"!");
}

void action::attack(std::string attacker, std::string defender, int dmg){
	addText(attacker+" deals "+intToString(dmg)+" DMG to "+defender+".");
}

void action::showHP(std::string subject, int hp){
	addText("("+subject+": "+intToString(hp)+" HP)");
}

void action::miss(std::string attacker, std::string defender){
	addText(attacker+" missed "+defender+".");
}

void action::usePot(std::string name){
	addText("PC drinks "+name+" Potion.");

}
void action::changeStat(std::string statname, std::string change, int amt){
	addText(statname+" "+change+intToString(amt));

}
