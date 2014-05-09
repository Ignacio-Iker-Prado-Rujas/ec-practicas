################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../44blib.c \
../8seg.c \
../buffer.c \
../keyboard.c \
../main.c \
../timer.c \
../uart.c 

ASM_SRCS += \
../44binit.asm \
../timer_init.asm 

OBJS += \
./44binit.o \
./44blib.o \
./8seg.o \
./buffer.o \
./keyboard.o \
./main.o \
./timer.o \
./timer_init.o \
./uart.o 

C_DEPS += \
./44blib.d \
./8seg.d \
./buffer.d \
./keyboard.d \
./main.d \
./timer.d \
./uart.d 

ASM_DEPS += \
./44binit.d \
./timer_init.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Windows GCC Assembler'
	arm-none-eabi-gcc -x assembler-with-cpp -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=arm7tdmi -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Windows GCC C Compiler'
	arm-none-eabi-gcc -O0 -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -mapcs-frame -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=arm7tdmi -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


