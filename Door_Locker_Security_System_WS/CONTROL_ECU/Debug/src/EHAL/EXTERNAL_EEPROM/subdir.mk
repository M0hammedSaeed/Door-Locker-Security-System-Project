################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/EHAL/EXTERNAL_EEPROM/external_eeprom.c 

OBJS += \
./src/EHAL/EXTERNAL_EEPROM/external_eeprom.o 

C_DEPS += \
./src/EHAL/EXTERNAL_EEPROM/external_eeprom.d 


# Each subdirectory must supply rules for building sources it contributes
src/EHAL/EXTERNAL_EEPROM/%.o: ../src/EHAL/EXTERNAL_EEPROM/%.c src/EHAL/EXTERNAL_EEPROM/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


