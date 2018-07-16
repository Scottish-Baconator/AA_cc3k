################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../anton/chamber.cc \
../anton/character.cc \
../anton/dwarf.cc \
../anton/elf.cc \
../anton/enemy.cc \
../anton/floor.cc \
../anton/game.cc \
../anton/gold.cc \
../anton/halfling.cc \
../anton/human.cc \
../anton/main.cc \
../anton/merchant.cc \
../anton/obj.cc \
../anton/orc.cc \
../anton/pPlayer.cc \
../anton/player.cc \
../anton/potion.cc \
../anton/potions.cc \
../anton/shade.cc \
../anton/stair.cc \
../anton/test.cc \
../anton/textdisplay.cc \
../anton/troll.cc \
../anton/vampire.cc 

O_SRCS += \
../anton/chamber.o \
../anton/character.o \
../anton/dwarf.o \
../anton/elf.o \
../anton/enemy.o \
../anton/floor.o \
../anton/game.o \
../anton/gold.o \
../anton/halfling.o \
../anton/human.o \
../anton/main.o \
../anton/merchant.o \
../anton/obj.o \
../anton/orc.o \
../anton/pPlayer.o \
../anton/player.o \
../anton/potion.o \
../anton/potions.o \
../anton/shade.o \
../anton/stair.o \
../anton/textdisplay.o \
../anton/troll.o 

CC_DEPS += \
./anton/chamber.d \
./anton/character.d \
./anton/dwarf.d \
./anton/elf.d \
./anton/enemy.d \
./anton/floor.d \
./anton/game.d \
./anton/gold.d \
./anton/halfling.d \
./anton/human.d \
./anton/main.d \
./anton/merchant.d \
./anton/obj.d \
./anton/orc.d \
./anton/pPlayer.d \
./anton/player.d \
./anton/potion.d \
./anton/potions.d \
./anton/shade.d \
./anton/stair.d \
./anton/test.d \
./anton/textdisplay.d \
./anton/troll.d \
./anton/vampire.d 

OBJS += \
./anton/chamber.o \
./anton/character.o \
./anton/dwarf.o \
./anton/elf.o \
./anton/enemy.o \
./anton/floor.o \
./anton/game.o \
./anton/gold.o \
./anton/halfling.o \
./anton/human.o \
./anton/main.o \
./anton/merchant.o \
./anton/obj.o \
./anton/orc.o \
./anton/pPlayer.o \
./anton/player.o \
./anton/potion.o \
./anton/potions.o \
./anton/shade.o \
./anton/stair.o \
./anton/test.o \
./anton/textdisplay.o \
./anton/troll.o \
./anton/vampire.o 


# Each subdirectory must supply rules for building sources it contributes
anton/%.o: ../anton/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


