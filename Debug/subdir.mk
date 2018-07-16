################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../chamber.cc \
../character.cc \
../dwarf.cc \
../elf.cc \
../enemy.cc \
../floor.cc \
../game.cc \
../gold.cc \
../halfling.cc \
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
../textdisplay.cc \
../troll.cc \
../vampire.cc 

O_SRCS += \
../chamber.o \
../character.o \
../dwarf.o \
../elf.o \
../enemy.o \
../floor.o \
../game.o \
../gold.o \
../halfling.o \
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
../troll.o 

CC_DEPS += \
./chamber.d \
./character.d \
./dwarf.d \
./elf.d \
./enemy.d \
./floor.d \
./game.d \
./gold.d \
./halfling.d \
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
./textdisplay.d \
./troll.d \
./vampire.d 

OBJS += \
./chamber.o \
./character.o \
./dwarf.o \
./elf.o \
./enemy.o \
./floor.o \
./game.o \
./gold.o \
./halfling.o \
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


