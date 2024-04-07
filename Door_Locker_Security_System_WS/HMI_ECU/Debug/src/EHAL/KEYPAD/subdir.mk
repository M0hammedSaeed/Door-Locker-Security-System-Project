################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/EHAL/KEYPAD/keypad.c 

OBJS += \
./src/EHAL/KEYPAD/keypad.o 

C_DEPS += \
./src/EHAL/KEYPAD/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
src/EHAL/KEYPAD/%.o: ../src/EHAL/KEYPAD/%.c src/EHAL/KEYPAD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


