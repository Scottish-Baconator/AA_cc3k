################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../chamber.cc \
../character.cc \
../enemy.cc \
../floor.cc \
../game.cc \
../human.cc \
../main.cc \
../textdisplay.cc 

CC_DEPS += \
./chamber.d \
./character.d \
./enemy.d \
./floor.d \
./game.d \
./human.d \
./main.d \
./textdisplay.d 

OBJS += \
./chamber.o \
./character.o \
./enemy.o \
./floor.o \
./game.o \
./human.o \
./main.o \
./textdisplay.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


