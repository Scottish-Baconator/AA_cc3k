################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../Alastair\ Putty/action.cc \
../Alastair\ Putty/chamber.cc \
../Alastair\ Putty/character.cc \
../Alastair\ Putty/dragon.cc \
../Alastair\ Putty/drow.cc \
../Alastair\ Putty/dwarf.cc \
../Alastair\ Putty/elf.cc \
../Alastair\ Putty/enemy.cc \
../Alastair\ Putty/floor.cc \
../Alastair\ Putty/game.cc \
../Alastair\ Putty/goblin.cc \
../Alastair\ Putty/gold.cc \
../Alastair\ Putty/halfling.cc \
../Alastair\ Putty/hoard.cc \
../Alastair\ Putty/human.cc \
../Alastair\ Putty/main.cc \
../Alastair\ Putty/merchant.cc \
../Alastair\ Putty/obj.cc \
../Alastair\ Putty/orc.cc \
../Alastair\ Putty/pPlayer.cc \
../Alastair\ Putty/player.cc \
../Alastair\ Putty/potion.cc \
../Alastair\ Putty/potions.cc \
../Alastair\ Putty/shade.cc \
../Alastair\ Putty/stair.cc \
../Alastair\ Putty/test.cc \
../Alastair\ Putty/textdisplay.cc \
../Alastair\ Putty/troll.cc \
../Alastair\ Putty/vampire.cc 

O_SRCS += \
../Alastair\ Putty/action.o \
../Alastair\ Putty/chamber.o \
../Alastair\ Putty/character.o \
../Alastair\ Putty/dragon.o \
../Alastair\ Putty/drow.o \
../Alastair\ Putty/dwarf.o \
../Alastair\ Putty/elf.o \
../Alastair\ Putty/enemy.o \
../Alastair\ Putty/floor.o \
../Alastair\ Putty/game.o \
../Alastair\ Putty/goblin.o \
../Alastair\ Putty/gold.o \
../Alastair\ Putty/halfling.o \
../Alastair\ Putty/hoard.o \
../Alastair\ Putty/human.o \
../Alastair\ Putty/main.o \
../Alastair\ Putty/merchant.o \
../Alastair\ Putty/obj.o \
../Alastair\ Putty/orc.o \
../Alastair\ Putty/pPlayer.o \
../Alastair\ Putty/player.o \
../Alastair\ Putty/potion.o \
../Alastair\ Putty/potions.o \
../Alastair\ Putty/shade.o \
../Alastair\ Putty/stair.o \
../Alastair\ Putty/textdisplay.o \
../Alastair\ Putty/troll.o \
../Alastair\ Putty/vampire.o 

CC_DEPS += \
./Alastair\ Putty/action.d \
./Alastair\ Putty/chamber.d \
./Alastair\ Putty/character.d \
./Alastair\ Putty/dragon.d \
./Alastair\ Putty/drow.d \
./Alastair\ Putty/dwarf.d \
./Alastair\ Putty/elf.d \
./Alastair\ Putty/enemy.d \
./Alastair\ Putty/floor.d \
./Alastair\ Putty/game.d \
./Alastair\ Putty/goblin.d \
./Alastair\ Putty/gold.d \
./Alastair\ Putty/halfling.d \
./Alastair\ Putty/hoard.d \
./Alastair\ Putty/human.d \
./Alastair\ Putty/main.d \
./Alastair\ Putty/merchant.d \
./Alastair\ Putty/obj.d \
./Alastair\ Putty/orc.d \
./Alastair\ Putty/pPlayer.d \
./Alastair\ Putty/player.d \
./Alastair\ Putty/potion.d \
./Alastair\ Putty/potions.d \
./Alastair\ Putty/shade.d \
./Alastair\ Putty/stair.d \
./Alastair\ Putty/test.d \
./Alastair\ Putty/textdisplay.d \
./Alastair\ Putty/troll.d \
./Alastair\ Putty/vampire.d 

OBJS += \
./Alastair\ Putty/action.o \
./Alastair\ Putty/chamber.o \
./Alastair\ Putty/character.o \
./Alastair\ Putty/dragon.o \
./Alastair\ Putty/drow.o \
./Alastair\ Putty/dwarf.o \
./Alastair\ Putty/elf.o \
./Alastair\ Putty/enemy.o \
./Alastair\ Putty/floor.o \
./Alastair\ Putty/game.o \
./Alastair\ Putty/goblin.o \
./Alastair\ Putty/gold.o \
./Alastair\ Putty/halfling.o \
./Alastair\ Putty/hoard.o \
./Alastair\ Putty/human.o \
./Alastair\ Putty/main.o \
./Alastair\ Putty/merchant.o \
./Alastair\ Putty/obj.o \
./Alastair\ Putty/orc.o \
./Alastair\ Putty/pPlayer.o \
./Alastair\ Putty/player.o \
./Alastair\ Putty/potion.o \
./Alastair\ Putty/potions.o \
./Alastair\ Putty/shade.o \
./Alastair\ Putty/stair.o \
./Alastair\ Putty/test.o \
./Alastair\ Putty/textdisplay.o \
./Alastair\ Putty/troll.o \
./Alastair\ Putty/vampire.o 


# Each subdirectory must supply rules for building sources it contributes
Alastair\ Putty/action.o: ../Alastair\ Putty/action.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/action.d" -MT"Alastair\ Putty/action.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/chamber.o: ../Alastair\ Putty/chamber.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/chamber.d" -MT"Alastair\ Putty/chamber.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/character.o: ../Alastair\ Putty/character.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/character.d" -MT"Alastair\ Putty/character.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/dragon.o: ../Alastair\ Putty/dragon.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/dragon.d" -MT"Alastair\ Putty/dragon.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/drow.o: ../Alastair\ Putty/drow.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/drow.d" -MT"Alastair\ Putty/drow.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/dwarf.o: ../Alastair\ Putty/dwarf.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/dwarf.d" -MT"Alastair\ Putty/dwarf.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/elf.o: ../Alastair\ Putty/elf.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/elf.d" -MT"Alastair\ Putty/elf.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/enemy.o: ../Alastair\ Putty/enemy.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/enemy.d" -MT"Alastair\ Putty/enemy.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/floor.o: ../Alastair\ Putty/floor.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/floor.d" -MT"Alastair\ Putty/floor.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/game.o: ../Alastair\ Putty/game.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/game.d" -MT"Alastair\ Putty/game.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/goblin.o: ../Alastair\ Putty/goblin.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/goblin.d" -MT"Alastair\ Putty/goblin.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/gold.o: ../Alastair\ Putty/gold.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/gold.d" -MT"Alastair\ Putty/gold.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/halfling.o: ../Alastair\ Putty/halfling.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/halfling.d" -MT"Alastair\ Putty/halfling.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/hoard.o: ../Alastair\ Putty/hoard.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/hoard.d" -MT"Alastair\ Putty/hoard.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/human.o: ../Alastair\ Putty/human.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/human.d" -MT"Alastair\ Putty/human.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/main.o: ../Alastair\ Putty/main.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/main.d" -MT"Alastair\ Putty/main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/merchant.o: ../Alastair\ Putty/merchant.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/merchant.d" -MT"Alastair\ Putty/merchant.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/obj.o: ../Alastair\ Putty/obj.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/obj.d" -MT"Alastair\ Putty/obj.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/orc.o: ../Alastair\ Putty/orc.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/orc.d" -MT"Alastair\ Putty/orc.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/pPlayer.o: ../Alastair\ Putty/pPlayer.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/pPlayer.d" -MT"Alastair\ Putty/pPlayer.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/player.o: ../Alastair\ Putty/player.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/player.d" -MT"Alastair\ Putty/player.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/potion.o: ../Alastair\ Putty/potion.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/potion.d" -MT"Alastair\ Putty/potion.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/potions.o: ../Alastair\ Putty/potions.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/potions.d" -MT"Alastair\ Putty/potions.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/shade.o: ../Alastair\ Putty/shade.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/shade.d" -MT"Alastair\ Putty/shade.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/stair.o: ../Alastair\ Putty/stair.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/stair.d" -MT"Alastair\ Putty/stair.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/test.o: ../Alastair\ Putty/test.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/test.d" -MT"Alastair\ Putty/test.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/textdisplay.o: ../Alastair\ Putty/textdisplay.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/textdisplay.d" -MT"Alastair\ Putty/textdisplay.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/troll.o: ../Alastair\ Putty/troll.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/troll.d" -MT"Alastair\ Putty/troll.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Alastair\ Putty/vampire.o: ../Alastair\ Putty/vampire.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Alastair Putty/vampire.d" -MT"Alastair\ Putty/vampire.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


