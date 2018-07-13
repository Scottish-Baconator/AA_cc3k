/*
 * main.cc
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */
#include "game.h"
#include <iostream>
#include <string>

game::dir convert(std::string s){
	switch (s[0]){
	case 'n':
		switch(s[1]){
		case 'w':
			return game::nw;
		case 'e':
			return game::ne;
		}
		return game::no;
	case 's':
		switch(s[1]){
		case 'w':
			return game::sw;
		case 'e':
			return game::se;
		}
		return game::so;
	case 'w':
		return game::we;
	case 'e':
		return game::ea;
	}
	return game::no;
}

int main(int argc, char *argv[]){
	std::string file;
	if(argc < 2){
		//std::cerr<<"2 arguments required.";
		//return 1;
		file = "./cc3kfloor.txt";
	}else{
		file = std::string(argv[1]);
	}
	game g = game(file);
	std::string s;
	while(std::cin >> s){
		if(s[0] == 'u'){
			g.use(convert(s.substr(2, 2)));
		}else if(s[0] == 'a'){
			g.attack(convert(s.substr(2, 2)));
		}else if(s[0] == 'f'){
			g.stop();
		}else if(s[0] == 'r'){
			g = game(file);
		}else if(s[0] == 'q'){
			break;
		}else{
			g.move(convert(s.substr(0, 2)));
		}
		g.step();
		g.render(std::cout);
	}
}


