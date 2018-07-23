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
	bool random = (argc < 2);
	if(argc < 2){
		file = "./cc3kblankfloor.txt";
	}else{
		file = std::string(argv[1]);
	}
	//std::cout<<random<<"\n";
	game g{file, random};


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
			g = game(file, !random);
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
		if(g.isWinner()){
			std::cout<<"Good job! You survived the dungeon."<<std::endl;
		}else{
			std::cout<<"Bad luck. You were killed in the dungeon."<<std::endl;
		}
		std::cout<<"You achieved a score of "<<g.getScore();
		std::cout<<" as a "<<g.getRace() << std::endl;
	}
}


