################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXT_INTERRUPT_Prog.c 

OBJS += \
./MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXT_INTERRUPT_Prog.o 

C_DEPS += \
./MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXT_INTERRUPT_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/INTERRUPT/EXTERNAL_INTERRUPT/%.o: ../MCAL/INTERRUPT/EXTERNAL_INTERRUPT/%.c MCAL/INTERRUPT/EXTERNAL_INTERRUPT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


