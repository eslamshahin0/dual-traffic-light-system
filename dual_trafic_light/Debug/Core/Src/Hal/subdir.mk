################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Hal/sw.c 

OBJS += \
./Core/Src/Hal/sw.o 

C_DEPS += \
./Core/Src/Hal/sw.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Hal/%.o Core/Src/Hal/%.su Core/Src/Hal/%.cyclo: ../Core/Src/Hal/%.c Core/Src/Hal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -Wno-incompatible-pointer-types -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Hal

clean-Core-2f-Src-2f-Hal:
	-$(RM) ./Core/Src/Hal/sw.cyclo ./Core/Src/Hal/sw.d ./Core/Src/Hal/sw.o ./Core/Src/Hal/sw.su

.PHONY: clean-Core-2f-Src-2f-Hal

