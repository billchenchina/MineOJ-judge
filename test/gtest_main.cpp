/*
 * gtest_main.cpp
 *
 *  Created on: 2017年6月28日
 *      Author: igronemyk
 */

#include <cstdio>
#include <gtest/gtest.h>
#include <MQSender.h>

GTEST_API_ int main(int argc, char **argv) {
    printf("Running main() from gtest_main.cc\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
