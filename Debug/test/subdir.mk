################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/test_JudgeData.cpp \
../test/test_JudgeResult.cpp \
../test/test_JudgeSideConfig.cpp \
../test/test_jsoncpp.cpp 

OBJS += \
./test/test_JudgeData.o \
./test/test_JudgeResult.o \
./test/test_JudgeSideConfig.o \
./test/test_jsoncpp.o 

CPP_DEPS += \
./test/test_JudgeData.d \
./test/test_JudgeResult.d \
./test/test_JudgeSideConfig.d \
./test/test_jsoncpp.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -I"/home/billchenchina/workspaces/Eclipse/Cpp/MineOJ-Judger/gtest_src" -I"/home/billchenchina/workspaces/Eclipse/Cpp/MineOJ-Judger/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


