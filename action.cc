/*
 * action.cc
 *
 *  Created on: Jul 17, 2018
 *      Author: ajsme
 */

#include "action.h"
#include <iostream>

void action::clear(){
	text="";
}

void action::addText(std::string txt){
	text += text=="" ? txt : " "+txt;
}

std::string action::printText(){
	std::string print = text+=".";
	clear();
	return print;
}
