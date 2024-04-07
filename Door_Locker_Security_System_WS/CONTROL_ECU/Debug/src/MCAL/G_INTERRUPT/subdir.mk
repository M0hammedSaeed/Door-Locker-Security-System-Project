################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MCAL/G_INTERRUPT/g_interrupt.c 

OBJS += \
./src/MCAL/G_INTERRUPT/g_interrupt.o 

C_DEPS += \
./src/MCAL/G_INTERRUPT/g_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
src/MCAL/G_INTERRUPT/%.o: ../src/MCAL/G_INTERRUPT/%.c src/MCAL/G_INTERRUPT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


