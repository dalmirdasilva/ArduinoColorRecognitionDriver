################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ColorRecognitionTCS230PI/ColorRecognitionTCS230PI.cpp 

OBJS += \
./ColorRecognitionTCS230PI/ColorRecognitionTCS230PI.o 

CPP_DEPS += \
./ColorRecognitionTCS230PI/ColorRecognitionTCS230PI.d 


# Each subdirectory must supply rules for building sources it contributes
ColorRecognitionTCS230PI/%.o: ../ColorRecognitionTCS230PI/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -I"/storage/microcontroller/arduino/driver/sensor/color/ColorRecognition" -I"/storage/microcontroller/arduino/driver/sensor/color/ColorRecognitionTCS230" -I"/storage/microcontroller/arduino/driver/sensor/color/ColorRecognitionTCS230PI" -I"/storage/microcontroller/arduino/modules/timers/TimerOne" -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


