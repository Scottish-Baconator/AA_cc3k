/*
 * main.cc
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */
#include "game.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

game::dir convert(std::string s){
	if(s.length()!=2){
		return game::no;
	}

	switch (s[0]){
		case 'n':
			switch(s[1]){
				case 'w':
					return game::nw;
					break;
				case 'e':
					return game::ne;
					break;
				default:
					return game::no;
					break;
			}
			break;
		case 's':
			switch(s[1]){
			case 'w':
				return game::sw;
				break;
			case 'e':
				return game::se;
				break;
			default:
				return game::no;
				break;
			}
			break;
		case 'w':
			return game::we;
			break;
		case 'e':
			return game::ea;
			break;
		default:
			return game::no;
			break;
	}

	return game::no;
}

int main(int argc, char *argv[]){
	std::string file;
	bool random = (argc < 2);
	bool extra = false;
	if(argc < 2){
		file = "./cc3kblankfloor.txt";
	}else{
		file = std::string(argv[1]);
		if(file[0] == '-'){
			extra = true;
			if(argc > 2){
				file = std::string(argv[2]);
				random = false;
			}else{
				file = "./cc3kblankfloor.txt";
				random = true;
			}
		}
	}
	srand(time(0));
	game *g = new game{file, random, extra};


	if(!g->goodRace()){
		return 0;
	}

	g->render(std::cout);

	std::string s;

	while(std::cin >> s){
		bool comp = false;
		if(s[0] == 'u'){
			std::cin >> s;
			comp = g->use(convert(s));
		}else if(s[0] == 'a'){
			std::cin >> s;
			comp = g->attack(convert(s));
		}else if(s[0] == 'f'){
			g->stop();
		}else if(s[0] == 'g'){
			g->gib();
		}else if(s[0] == 'r'){
			delete g;
			g = new game{file, random, extra};
			if(!g->goodRace()){
				return 0;
			}
			g->render(std::cout);
			continue;
		}else if(s[0] == 'q'){
			break;
		}else{
			g->move(convert(s));
			comp = true;
		}
		if(comp){
			g->step();
			g->render(std::cout);
		}
		if(g->isDone()){
			break;
		}
	}


	if(g->isDone()){
		if(g->isWinner()){
			std::cout<<"Good job! You survived the dungeon."<<std::endl;
		}else{
			std::cout<<"Bad luck. You were killed in the dungeon."<<std::endl;
		}
		std::cout<<"You achieved a score of "<<g->getScore();
		std::cout<<" as a "<<g->getRace() << std::endl;
	}
}

