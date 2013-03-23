################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ColorRecognition/ColorRecognition.cpp 

OBJS += \
./ColorRecognition/ColorRecognition.o 

CPP_DEPS += \
./ColorRecognition/ColorRecognition.d 


# Each subdirectory must supply rules for building sources it contributes
ColorRecognition/%.o: ../ColorRecognition/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -I"/storage/microcontroller/arduino/driver/sensor/color/ColorRecognition" -I"/storage/microcontroller/arduino/driver/sensor/color/ColorRecognitionTCS230" -I"/storage/microcontroller/arduino/driver/sensor/color/ColorRecognitionTCS230PI" -I"/storage/microcontroller/arduino/modules/timers/TimerOne" -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


