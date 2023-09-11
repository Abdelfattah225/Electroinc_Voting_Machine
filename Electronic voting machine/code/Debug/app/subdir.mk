################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/app.c \
../app/main.c 

OBJS += \
./app/app.o \
./app/main.o 

C_DEPS += \
./app/app.d \
./app/main.d 


# Each subdirectory must supply rules for building sources it contributes
app/%.o: ../app/%.c app/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Embedded Systems\GDSC - embededd system\interfaceing\Projects\vote machine\voting\app" -I"D:\Embedded Systems\GDSC - embededd system\interfaceing\Projects\vote machine\voting\HAL\keypad" -I"D:\Embedded Systems\GDSC - embededd system\interfaceing\Projects\vote machine\voting\HAL\LCD" -I"D:\Embedded Systems\GDSC - embededd system\interfaceing\Projects\vote machine\voting\LIB" -I"D:\Embedded Systems\GDSC - embededd system\interfaceing\Projects\vote machine\voting\MCAL\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


