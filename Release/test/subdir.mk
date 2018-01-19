################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/gtest_main.cpp \
../test/test_JudgeData.cpp \
../test/test_JudgeResult.cpp \
../test/test_JudgeSideConfig.cpp \
../test/test_MQSender.cpp \
../test/test_jsoncpp.cpp 

OBJS += \
./test/gtest_main.o \
./test/test_JudgeData.o \
./test/test_JudgeResult.o \
./test/test_JudgeSideConfig.o \
./test/test_MQSender.o \
./test/test_jsoncpp.o 

CPP_DEPS += \
./test/gtest_main.d \
./test/test_JudgeData.d \
./test/test_JudgeResult.d \
./test/test_JudgeSideConfig.d \
./test/test_MQSender.d \
./test/test_jsoncpp.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


