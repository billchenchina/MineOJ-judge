/*
 * test_MQSender.cpp
 *
 *  Created on: 2018年1月20日
 *      Author: billchenchina
 */


#include <gtest/gtest.h>

#include "MQPublisher.h"
#include "MQConsumer.h"

TEST(test_MQSender, PublishAndConsume) {
    std::string message="test_message";
    MineOJ::MQPublisher publisher("amqp://127.0.0.1/",message);
    publisher.exec();
    MineOJ::MQConsumer consumer;
    std::string s=consumer.exec();
    EXPECT_EQ(s,message);

}
