################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../action.cc \
../chamber.cc \
../character.cc \
../dragon.cc \
../drow.cc \
../dwarf.cc \
../elf.cc \
../enemy.cc \
../floor.cc \
../game.cc \
../goblin.cc \
../gold.cc \
../halfling.cc \
../hoard.cc \
../human.cc \
../main.cc \
../merchant.cc \
../obj.cc \
../orc.cc \
../pPlayer.cc \
../player.cc \
../potion.cc \
../potions.cc \
../shade.cc \
../stair.cc \
../test.cc \
../textdisplay.cc \
../troll.cc \
../vampire.cc 

O_SRCS += \
../action.o \
../chamber.o \
../character.o \
../dragon.o \
../drow.o \
../dwarf.o \
../elf.o \
../enemy.o \
../floor.o \
../game.o \
../goblin.o \
../gold.o \
../halfling.o \
../hoard.o \
../human.o \
../main.o \
../merchant.o \
../obj.o \
../orc.o \
../pPlayer.o \
../player.o \
../potion.o \
../potions.o \
../shade.o \
../stair.o \
../textdisplay.o \
../troll.o \
../vampire.o 

CC_DEPS += \
./action.d \
./chamber.d \
./character.d \
./dragon.d \
./drow.d \
./dwarf.d \
./elf.d \
./enemy.d \
./floor.d \
./game.d \
./goblin.d \
./gold.d \
./halfling.d \
./hoard.d \
./human.d \
./main.d \
./merchant.d \
./obj.d \
./orc.d \
./pPlayer.d \
./player.d \
./potion.d \
./potions.d \
./shade.d \
./stair.d \
./test.d \
./textdisplay.d \
./troll.d \
./vampire.d 

OBJS += \
./action.o \
./chamber.o \
./character.o \
./dragon.o \
./drow.o \
./dwarf.o \
./elf.o \
./enemy.o \
./floor.o \
./game.o \
./goblin.o \
./gold.o \
./halfling.o \
./hoard.o \
./human.o \
./main.o \
./merchant.o \
./obj.o \
./orc.o \
./pPlayer.o \
./player.o \
./potion.o \
./potions.o \
./shade.o \
./stair.o \
./test.o \
./textdisplay.o \
./troll.o \
./vampire.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


