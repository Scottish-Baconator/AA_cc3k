/*
 * game.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */
#include "game.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "potion.h"
#include "enemy.h"
#include "gold.h"
#include "stair.h"
#include "action.h"
#include "floor.h"

bool one(char c, char a[], int l){
	for(int i = 0;i < l;i++){
		if(c == a[i]){
			return true;
		}
	}
	return false;
}

char game::racePick(){
	using namespace std;
	cout<<"What race would you like to be?\n";
	cout<<"   name     HP  Atk/Def  Special power\n";
	cout<<"s: Shade   (125, 25/25)\n";
	cout<<"d: Drow    (150, 25/15)  (all Potions effects x1.5)\n";
	cout<<"v: Vampire (50,  25/25)  (5HP gained per atk, no max HP)\n";
	cout<<"t: Troll   (120, 25/15)  (gain 5HP per turn)\n";
	cout<<"g: Goblin  (110, 15/20)  (5 gold per enemy killed)\n";
	string in;
	if(cin>>in){
		return in[0];
	}
	return 'q';
}

bool oneOf(char a, char b[], int l){
	for(int i =0;i < l;i++){
		if(a == b[i]){
			return true;
		}
	}
	return false;
}

char game::getRace(){
	return race;
}

bool game::goodRace(){
	char races[] = {'s', 'd', 'v', 'g', 't'};
	return oneOf(race, races, 5);
}

game::game(std::string s): floorNum(1), a{new action()},f(new level{s,a,floorNum}){
	char races[] = {'s', 'd', 'v', 'g', 't'};
	done = false;
	do{
		race = racePick();
		if(race == 'q'){
			return;
		}
	}while(!oneOf(race, races, 5));
	file = s;
	int pCh = rand()%5;
	pC = f->getChmbr(pCh)->random();
	switch (race){
	case 's':
		p = new shade(pC);
		break;
	case 'd':
		p = new drow(pC);
		break;
	case 'v':
		p = new vampire(pC);
		break;
	case 't':
		p = new troll(pC);
		break;
	case 'g':
		p = new goblin(pC);
		break;
	}
	pp = p;
	gld = 0;
	f->add(pp, pC);
	paused = false;
	//for testing purposes
	stairs = f->getChmbr(pCh)->random();
//	stairs = f->getChmbr(4 - pCh)->random();
	f->add(new stair(stairs), stairs);
}

void game::nextLevel(){
	floorNum++;
	if(floorNum == 6){
		done = true;
		return;
	}
	//must copy FIRST since delete f deletes our player!
	p = new player{*p};
	delete f;
	f = new level{file,a, floorNum};
	int pCh = rand()%5;
	pC = f->getChmbr(pCh)->random();
	pp = p;
	f->add(pp, pC);
	paused = false;
	stairs = f->getChmbr(4 - pCh)->random();
	f->add(new stair(stairs), stairs);
}

void game::step(){
	if(pp->getHP() <= 0){
		done = true;
		return;
	}
	if(!paused){
		f->step();
	}
}

void game::render(std::ostream &out){
	f->render(out, pp, gld);
}

coord getCoord(enum game::dir d, coord pC){
	coord tr = pC;
	switch (d){
		case game::no:
			tr.y--;
			break;
		case game::so:
			tr.y++;
			break;
		case game::we:
			tr.x--;
			break;
		case game::ea:
			tr.x++;
			break;
		case game::ne:
			tr.y--;tr.x++;
			break;
		case game::nw:
			tr.y--;tr.x--;
			break;
		case game::se:
			tr.y++;tr.x++;
			break;
		case game::sw:
			tr.y++;tr.x--;
			break;
		}
	return tr;
}

//Moves player in direction dir
bool game::move(dir d){
	//temp is the coordinates the player is trying to move in
	coord temp = getCoord(d, pC);


	std::string dirtext="North";
	switch (d){
		case game::no:
			dirtext="North";
			break;
		case game::so:
			dirtext="South";
			break;
		case game::we:
			dirtext="West";
			break;
		case game::ea:
			dirtext="East";
			break;
		case game::ne:
			dirtext="Northeast";
			break;
		case game::nw:
			dirtext="Northwest";
			break;
		case game::se:
			dirtext="Southeast";
			break;
		case game::sw:
			dirtext="Southwest";
			break;
		}

	//std::cerr<<"pot"<<std::endl;
	if(f->canWalk(temp) == level::All || f->canWalk(temp) == level::PC){


		//This empty makes it so we dont check the render of an empty tile
		//getObj doesnt work on an empty tile - ill probably add a throw line to that eventually
		if(!f->empty(temp)){
			if((f->getObj(temp)->render() == '\\')){
				nextLevel();
			}else if(f->getObj(temp)->render() == 'G'){
				int newgld = ((gold *) (f->getObj(temp)))->getVal();
				gld += newgld;
				a->addGold(newgld);
				f->remove(temp);
			} else {
				a->cantMove(dirtext);
				return false;
			}

		}

		a->movePC(dirtext);

		//std::cerr<<"a"<<std::endl;
		if(f->move(pC, temp)){
			//std::cerr<<"to"<<std::endl;
			pC = temp;

			return true;
		}

	}else{
		a->cantMove(dirtext);
	}


	return false;
}

bool game::use(dir d){
	coord temp = getCoord(d, pC);
	if(f->getObj(temp)->render() == 'P'){
		potion *pot = (potion *) f->getObj(temp);
		pp = pot->effect(pp);
		pot->displayEffect(a);
		f->update(pp, pC);
		f->remove(temp);
		return true;
	}
	return false;
}

bool game::attack(dir d){
	char enemies[] = {'H','W','E','O','M','D','L'};
	coord temp = getCoord(d, pC);
	if(one(f->getObj(temp)->render(), enemies, 7)){
		std::cerr << "hello!" << std::endl;
		enemy* tAtk = (enemy*)f->getObj(temp);
		pp->attack(tAtk, a);
		a->showHP(tAtk->getName(), tAtk->getHP());
		if(tAtk->getHP() < 0){
			tAtk->drop(f);
			f->remove(temp);
		}
		return true;
	}
	return false;
}

void game::stop(){
	paused = !paused;
}

bool game::isDone(){
	return done;
}

int game::getGold(){
	return gld;
}

int game::getHP(){
	return pp->getHP();
}
