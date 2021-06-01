################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Brasil.c \
../source/Config.c \
../source/Interrupcoes.c \
../source/clock_mcglite.c \
../source/mtb.c \
../source/semihost_hardfault.c 

OBJS += \
./source/Brasil.o \
./source/Config.o \
./source/Interrupcoes.o \
./source/clock_mcglite.o \
./source/mtb.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/Brasil.d \
./source/Config.d \
./source/Interrupcoes.d \
./source/clock_mcglite.d \
./source/mtb.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL33Z64VLH4 -DCPU_MKL33Z64VLH4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\Rosimar\Documents\MCUXpressoIDE_11.3.1_5262\workspace\Brasil\board" -I"C:\Users\Rosimar\Documents\MCUXpressoIDE_11.3.1_5262\workspace\Brasil\source" -I"C:\Users\Rosimar\Documents\MCUXpressoIDE_11.3.1_5262\workspace\Brasil" -I"C:\Users\Rosimar\Documents\MCUXpressoIDE_11.3.1_5262\workspace\Brasil\drivers" -I"C:\Users\Rosimar\Documents\MCUXpressoIDE_11.3.1_5262\workspace\Brasil\device" -I"C:\Users\Rosimar\Documents\MCUXpressoIDE_11.3.1_5262\workspace\Brasil\CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


