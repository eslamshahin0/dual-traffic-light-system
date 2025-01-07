################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/App/ew_road.c \
../Core/Src/App/ns_road.c \
../Core/Src/App/pedestrian.c 

OBJS += \
./Core/Src/App/ew_road.o \
./Core/Src/App/ns_road.o \
./Core/Src/App/pedestrian.o 

C_DEPS += \
./Core/Src/App/ew_road.d \
./Core/Src/App/ns_road.d \
./Core/Src/App/pedestrian.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/App/%.o Core/Src/App/%.su Core/Src/App/%.cyclo: ../Core/Src/App/%.c Core/Src/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -Wno-incompatible-pointer-types -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-App

clean-Core-2f-Src-2f-App:
	-$(RM) ./Core/Src/App/ew_road.cyclo ./Core/Src/App/ew_road.d ./Core/Src/App/ew_road.o ./Core/Src/App/ew_road.su ./Core/Src/App/ns_road.cyclo ./Core/Src/App/ns_road.d ./Core/Src/App/ns_road.o ./Core/Src/App/ns_road.su ./Core/Src/App/pedestrian.cyclo ./Core/Src/App/pedestrian.d ./Core/Src/App/pedestrian.o ./Core/Src/App/pedestrian.su

.PHONY: clean-Core-2f-Src-2f-App

