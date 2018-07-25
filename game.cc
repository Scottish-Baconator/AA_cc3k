/*
 * game.cc
 *
 *  Created on: Jul 12, 2018
 *      Author: alicy
 */
#include <fstream>
#include "game.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "bugbear.h"
#include "troll.h"
#include "goblin.h"
#include "potion.h"
#include "enemy.h"
#include "gold.h"
#include "stair.h"
#include "action.h"
#include "floor.h"
#include "obj.h"


coord find(char c, std::string file, int floorNum){
	std::ifstream in;
	in.open(file);

	//2000 chars in a floor
	in.ignore(CHAR_IN_FLOOR * (floorNum - 1));
	char cur = '0';
	for(int i = 0;i < 25;i++){
		for(int j = 0;j < 79;j++){
			in.get(cur);
			if(cur == c){
				return coord(j, i);
			}
		}
		in.ignore(1);
	}
	return coord(0,0);
}

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
	cout<<"   Name     HP  Atk/Def  Special power\n";
	cout<<"s: Shade   (125, 25/25)  (1.5x Score at end of game)\n";
	cout<<"d: Drow    (150, 25/15)  (All Potions effects x1.5)\n";
	cout<<"v: Vampire (50,  25/25)  (5HP gained per atk, no max HP)\n";
	cout<<"t: Troll   (120, 25/15)  (Recover 5HP per turn)\n";
	cout<<"g: Goblin  (110, 15/20)  (5 gold per enemy killed)\n";
	if(extra){
	cout<<"b: Bugbear (150, 25/25)  (takes 5 less damage per attack) (score x0.75)\n";
	}
	char in;
	if(cin>>in){
		return in;
	}
	return 'q';
}

bool inArr(char a, char b[], int l){
	for(int i =0;i < l;i++){
		if(a == b[i]){
			return true;
		}
	}
	return false;
}

std::string game::getRace(){
	return pp->getRace();
}

bool game::goodRace(){
	char races[] = {'s', 'd', 'v', 'g', 't', 'b'};
	return inArr(race, races, 6);
}




game::game(std::string fl, bool randomize, bool ex): randomize{randomize},file{fl},a{new action()},f{ new level{fl, a, floorNum, randomize}}{
	extra = ex;
	do{
		race = racePick();
		if(race == 'q'){
			return;
		}
	}while(!goodRace());

	int pCh;
	if(randomize){
		pCh = f->getRandomChamber();
		pC = f->getChmbr(pCh)->random();
	}else{
		pC = find('@', file, floorNum);
		coord sc = find('\\', file, floorNum);
		f->add(new stair{sc},sc);
	}
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
		case 'b':
			p = new bugbear(pC);
			break;
	}

	pp = p;
	f->add(pp, pC);

	if(randomize){
		f->randGen(pCh, extra);
	}
}

void game::nextLevel(){
	if(floorNum == MAX_FLOORS){
		done = true;
		return;
	}
	floorNum++;
	//must copy FIRST since delete f deletes our player!
	int HP = pp->getHP();
	p = new player{*p};
	p->setHP(HP);
	delete f;
	f = new level{file,a, floorNum, randomize};

	int pCh;
	if(randomize){
		pCh = f->getRandomChamber();
		pC = f->getChmbr(pCh)->random();
	}else{
		pC = find('@', file, floorNum);
		coord sc = find('\\', file, floorNum);
		f->add(new stair{sc},sc);
	}
	p->chngPos(pC);

	pp = p;
	f->add(pp, pC);

	if(randomize){
		f->randGen(pCh, extra);
	}
}

void game::step(){
	if(!paused){
		f->step(a);
	}
	if(pp->getHP() <= 0){
		done = true;
		return;
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
				return false;
			}else if(f->getObj(temp)->render() == 'G'){
				if(static_cast<gold*> (f->getObj(temp))->getPick()){
					int newgld = static_cast<gold*> ((f->getObj(temp)))->getVal();
					gld += newgld;
					a->addGold(newgld);
					f->remove(temp);
				}else{
					tHoard = f->getObj(temp);
					bHoard = true;
					f->update(nullptr, temp);
				}
			} else {
				a->cantMove(dirtext);
				return false;
			}

		}

		a->movePC(dirtext);

		if(f->move(pC, temp)){
			if(!bHoard && (tHoard != nullptr)){
				//if(tHoard == nullptr){
				//	std::cout<<"Ther be no dragons here!\n";
				//}else{
				//	std::cout<<"Thar be dragons\n";
				//	std::cout<<"Here be dragons: "<<tHoard->getPos()<<"\n";
				//}
				f->add(tHoard, pC);
				tHoard = nullptr;
			}
			if(bHoard){
				bHoard = false;
			}
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

	if(!f->empty(temp) && f->getObj(temp)->render() == 'P'){
		potion *pot = static_cast<potion*> (f->getObj(temp));
		pot->displayEffect(a, pp);
		pp = pot->effect(pp);
		f->update(pp, pC);
		f->remove(temp);
		return true;
	}

	return false;
}

bool game::attack(dir d){
	char enemies[] = {'H','W','E','O','M','D','L'};
	coord temp = getCoord(d, pC);

	if(!f->empty(temp) && one(f->getObj(temp)->render(), enemies, 7)){
		enemy* tAtk = static_cast<enemy*> (f->getObj(temp));
		pp->attack(tAtk, a);
		a->showHP(tAtk->getName(), tAtk->getHP());

		if(tAtk->getHP() <= 0){

			if(pp->canSteal()){
				gld += tAtk->stealAmt();
			}

			a->slay(tAtk->getName());
			tAtk->drop(f);
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

bool game::isWinner(){
	return pp->getHP()>0;
}

int game::getScore(){
	return gld*pp->scoreMultiplier();
}

void game::gotoNext(){
	nextLevel();
}

game::~game(){
	delete f;
	delete a;
	delete tHoard;
}
