/*
 * main.cc
 *
 *  Created on: Jul 11, 2018
 *      Author: alicy
 */
#include "game.h"

int main(int argc, char *argv[]){
	if(argc == 2){
		game g(argv[1], false);
	}else{
		game g(argv[1], true);
	}
}


