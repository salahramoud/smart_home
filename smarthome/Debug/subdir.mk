################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../Keypad.c \
../LCD.c \
../LDR.c \
../Lm35_Sensor.c \
../Servo.c \
../Timer.c \
../USART.c \
../main.c 

OBJS += \
./ADC.o \
./Keypad.o \
./LCD.o \
./LDR.o \
./Lm35_Sensor.o \
./Servo.o \
./Timer.o \
./USART.o \
./main.o 

C_DEPS += \
./ADC.d \
./Keypad.d \
./LCD.d \
./LDR.d \
./Lm35_Sensor.d \
./Servo.d \
./Timer.d \
./USART.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


