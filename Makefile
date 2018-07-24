# a4q5
cCXX=g++
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall -Werror -Werror=vla -MMD -g
OBJECTS=dragon.o hoard.o action.o obj.o chamber.o character.o enemy.o vampire.o player.o dwarf.o stair.o orc.o elf.o halfling.o merchant.o human.o shade.o drow.o troll.o goblin.o floor.o game.o potion.o potions.o pPlayer.o gold.o textdisplay.o main.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean

