################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../include/jsoncpp.cpp 

OBJS += \
./include/jsoncpp.o 

CPP_DEPS += \
./include/jsoncpp.d 


# Each subdirectory must supply rules for building sources it contributes
include/%.o: ../include/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


