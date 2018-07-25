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
				case 'e':
					return game::ne;
				case 'o':
					return game::no;
			}
		case 's':
			switch(s[1]){
			case 'w':
				return game::sw;
			case 'e':
				return game::se;
			case 'o':
				return game::so;
			}
		case 'w':
			return game::we;
		case 'e':
			return game::ea;
	}

	return game::no;
}

int main(int argc, char *argv[]){
	std::string file;
	bool random = true;
	bool extra = false;
	int args = 2;
  
  if (argc > 1 && std::string(argv[1])=="-e"){
    extra = true;
    ++args;
  }
  
	if(argc < args){
		file = "./cc3kblankfloor.txt";
	}else if (std::string(argv[args-1])=="extra_big"){
		std::cerr << "gello" << std::endl;
		file = "./cc3kblankfloor2.txt";
	}else if (std::string(argv[args-1])=="extra_small"){
		std::cerr << "gello" << std::endl;
		file = "./cc3kblankfloor3.txt";
	} else {
		file = std::string(argv[args-1]);
		random = false;

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
		}
		g->render(std::cout);
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

