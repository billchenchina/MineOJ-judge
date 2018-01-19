################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Config.cpp \
../src/JudgeData.cpp \
../src/JudgePoint.cpp \
../src/JudgeResult.cpp \
../src/JudgeSideConfig.cpp \
../src/MQConsumer.cpp \
../src/MQPublisher.cpp \
../src/RabbitmqConfig.cpp 

OBJS += \
./src/Config.o \
./src/JudgeData.o \
./src/JudgePoint.o \
./src/JudgeResult.o \
./src/JudgeSideConfig.o \
./src/MQConsumer.o \
./src/MQPublisher.o \
./src/RabbitmqConfig.o 

CPP_DEPS += \
./src/Config.d \
./src/JudgeData.d \
./src/JudgePoint.d \
./src/JudgeResult.d \
./src/JudgeSideConfig.d \
./src/MQConsumer.d \
./src/MQPublisher.d \
./src/RabbitmqConfig.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


