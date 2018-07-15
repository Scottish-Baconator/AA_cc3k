# a4q5
0;136;0cCXX=g++
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall -Werror -Werror=vla -MMD -g
OBJECTS=obj.o chamber.o character.o enemy.o player.o orc.o elf.o halfling.o troll.o merchant.o human.o shade.o floor.o game.o potion.o potions.o pPlayer.o gold.o textdisplay.o main.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean

