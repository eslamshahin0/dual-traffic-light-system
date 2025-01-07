################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Os/os.c 

OBJS += \
./Core/Src/Os/os.o 

C_DEPS += \
./Core/Src/Os/os.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Os/%.o Core/Src/Os/%.su Core/Src/Os/%.cyclo: ../Core/Src/Os/%.c Core/Src/Os/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -Wno-incompatible-pointer-types -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Os

clean-Core-2f-Src-2f-Os:
	-$(RM) ./Core/Src/Os/os.cyclo ./Core/Src/Os/os.d ./Core/Src/Os/os.o ./Core/Src/Os/os.su

.PHONY: clean-Core-2f-Src-2f-Os

