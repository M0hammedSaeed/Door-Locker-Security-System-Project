################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/EHAL/BUZZER/buzzer.c 

OBJS += \
./src/EHAL/BUZZER/buzzer.o 

C_DEPS += \
./src/EHAL/BUZZER/buzzer.d 


# Each subdirectory must supply rules for building sources it contributes
src/EHAL/BUZZER/%.o: ../src/EHAL/BUZZER/%.c src/EHAL/BUZZER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


