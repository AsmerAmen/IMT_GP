################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Driver.c \
../AVR_2_main.c \
../DIO.c \
../DigExInterrupt.c \
../LCD.c \
../croutine.c \
../heap_3.c \
../list.c \
../port.c \
../queue.c \
../tasks.c \
../timers.c 

OBJS += \
./ADC_Driver.o \
./AVR_2_main.o \
./DIO.o \
./DigExInterrupt.o \
./LCD.o \
./croutine.o \
./heap_3.o \
./list.o \
./port.o \
./queue.o \
./tasks.o \
./timers.o 

C_DEPS += \
./ADC_Driver.d \
./AVR_2_main.d \
./DIO.d \
./DigExInterrupt.d \
./LCD.d \
./croutine.d \
./heap_3.d \
./list.d \
./port.d \
./queue.d \
./tasks.d \
./timers.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


