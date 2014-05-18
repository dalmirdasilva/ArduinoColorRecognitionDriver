################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ColorRecognitionTCS230PI/examples/simple_read/simple_read.c 

OBJS += \
./ColorRecognitionTCS230PI/examples/simple_read/simple_read.o 

C_DEPS += \
./ColorRecognitionTCS230PI/examples/simple_read/simple_read.d 


# Each subdirectory must supply rules for building sources it contributes
ColorRecognitionTCS230PI/examples/simple_read/%.o: ../ColorRecognitionTCS230PI/examples/simple_read/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


