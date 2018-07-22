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
	if(s.length()!=2){
		return game::no;
	}
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
		file = "./cc3kblankfloor.txt";
	}else{
		file = std::string(argv[1]);
	}

	game g{file};

	if(!g.goodRace()){
		return 0;
	}

	g.render(std::cout);
	std::string s;

	while(std::cin >> s){
		bool comp = false;
		if(s[0] == 'u'){
			std::cin >> s;
			comp = g.use(convert(s));
		}else if(s[0] == 'a'){
			std::cin >> s;
			comp = g.attack(convert(s));
		}else if(s[0] == 'f'){
			g.stop();
		}else if(s[0] == 'r'){
			g = game(file);
		}else if(s[0] == 'q'){
			break;
		}else{
			g.move(convert(s));
			comp = true;
		}
		if(comp){
			g.step();
			g.render(std::cout);
		}
		if(g.isDone()){
			break;
		}
	}
	if(g.isDone()){
		if(g.getHP() <= 0){
			std::cout<<"Bad luck. You were killed in the dungeon.\n";
		}else{
			std::cout<<"Good job! You survived the dungeon.\n";
		}
		std::cout<<"You achieved a score of ";
		if(g.getRace() == 's'){
			std::cout<<(g.getGold() * 1.5);
		}else{
			std::cout<<(g.getGold());
		}
		std::cout<<" as a ";
		switch (g.getRace()){
		case 's':
			std::cout<<"shade";
			break;
		case 'd':
			std::cout<<"shade";
			break;
		case 'v':
			std::cout<<"vampire";
			break;
		case 't':
			std::cout<<"troll";
			break;
		case 'g':
			std::cout<<"goblin";
			break;
		}
	}
}


