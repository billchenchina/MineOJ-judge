################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Config.cpp \
../src/FileReader.cpp \
../src/JudgeData.cpp \
../src/JudgePoint.cpp \
../src/JudgeResult.cpp \
../src/JudgeSideConfig.cpp \
../src/MQConsumer.cpp \
../src/MQPublisher.cpp \
../src/MQSignalConsumer.cpp \
../src/MQTestDataConsumer.cpp \
../src/RabbitmqConfig.cpp \
../src/Sandbox.cpp \
../src/jsoncpp.cpp 

OBJS += \
./src/Config.o \
./src/FileReader.o \
./src/JudgeData.o \
./src/JudgePoint.o \
./src/JudgeResult.o \
./src/JudgeSideConfig.o \
./src/MQConsumer.o \
./src/MQPublisher.o \
./src/MQSignalConsumer.o \
./src/MQTestDataConsumer.o \
./src/RabbitmqConfig.o \
./src/Sandbox.o \
./src/jsoncpp.o 

CPP_DEPS += \
./src/Config.d \
./src/FileReader.d \
./src/JudgeData.d \
./src/JudgePoint.d \
./src/JudgeResult.d \
./src/JudgeSideConfig.d \
./src/MQConsumer.d \
./src/MQPublisher.d \
./src/MQSignalConsumer.d \
./src/MQTestDataConsumer.d \
./src/RabbitmqConfig.d \
./src/Sandbox.d \
./src/jsoncpp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -I"/home/billchenchina/workspaces/Eclipse/Cpp/MineOJ-Judger/gtest_src" -I"/home/billchenchina/workspaces/Eclipse/Cpp/MineOJ-Judger/include" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


