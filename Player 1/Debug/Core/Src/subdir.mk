################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/adc.c \
../Core/Src/ball.c \
../Core/Src/bluetooth.c \
../Core/Src/display.c \
../Core/Src/dma.c \
../Core/Src/fonts.c \
../Core/Src/game.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/paddle.c \
../Core/Src/sd.c \
../Core/Src/spi.c \
../Core/Src/st7735.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/tim.c \
../Core/Src/usart.c \
../Core/Src/user_diskio_spi.c 

OBJS += \
./Core/Src/adc.o \
./Core/Src/ball.o \
./Core/Src/bluetooth.o \
./Core/Src/display.o \
./Core/Src/dma.o \
./Core/Src/fonts.o \
./Core/Src/game.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/paddle.o \
./Core/Src/sd.o \
./Core/Src/spi.o \
./Core/Src/st7735.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/tim.o \
./Core/Src/usart.o \
./Core/Src/user_diskio_spi.o 

C_DEPS += \
./Core/Src/adc.d \
./Core/Src/ball.d \
./Core/Src/bluetooth.d \
./Core/Src/display.d \
./Core/Src/dma.d \
./Core/Src/fonts.d \
./Core/Src/game.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/paddle.d \
./Core/Src/sd.d \
./Core/Src/spi.d \
./Core/Src/st7735.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/tim.d \
./Core/Src/usart.d \
./Core/Src/user_diskio_spi.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/adc.cyclo ./Core/Src/adc.d ./Core/Src/adc.o ./Core/Src/adc.su ./Core/Src/ball.cyclo ./Core/Src/ball.d ./Core/Src/ball.o ./Core/Src/ball.su ./Core/Src/bluetooth.cyclo ./Core/Src/bluetooth.d ./Core/Src/bluetooth.o ./Core/Src/bluetooth.su ./Core/Src/display.cyclo ./Core/Src/display.d ./Core/Src/display.o ./Core/Src/display.su ./Core/Src/dma.cyclo ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/dma.su ./Core/Src/fonts.cyclo ./Core/Src/fonts.d ./Core/Src/fonts.o ./Core/Src/fonts.su ./Core/Src/game.cyclo ./Core/Src/game.d ./Core/Src/game.o ./Core/Src/game.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/paddle.cyclo ./Core/Src/paddle.d ./Core/Src/paddle.o ./Core/Src/paddle.su ./Core/Src/sd.cyclo ./Core/Src/sd.d ./Core/Src/sd.o ./Core/Src/sd.su ./Core/Src/spi.cyclo ./Core/Src/spi.d ./Core/Src/spi.o ./Core/Src/spi.su ./Core/Src/st7735.cyclo ./Core/Src/st7735.d ./Core/Src/st7735.o ./Core/Src/st7735.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/tim.cyclo ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su ./Core/Src/user_diskio_spi.cyclo ./Core/Src/user_diskio_spi.d ./Core/Src/user_diskio_spi.o ./Core/Src/user_diskio_spi.su

.PHONY: clean-Core-2f-Src

