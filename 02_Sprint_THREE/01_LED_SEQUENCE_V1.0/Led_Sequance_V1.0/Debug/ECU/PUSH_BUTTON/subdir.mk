################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECU/PUSH_BUTTON/PB_prog.c 

OBJS += \
./ECU/PUSH_BUTTON/PB_prog.o 

C_DEPS += \
./ECU/PUSH_BUTTON/PB_prog.d 


# Each subdirectory must supply rules for building sources it contributes
ECU/PUSH_BUTTON/%.o: ../ECU/PUSH_BUTTON/%.c ECU/PUSH_BUTTON/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


