/*
 * test_JudgeSideConfig.cpp
 *
 *  Created on: 2018年1月20日
 *      Author: billchenchina
 */
#include <gtest/gtest.h>

#include "JudgeSideConfig.h"

TEST(test_JudgeSideConfig, ReadAndParse) {
    Json::Value json;
    json["rabbitmq"]["username"] = "guest";
    json["rabbitmq"]["password"] = "guest";
    json["rabbitmq"]["ip"] = "127.0.0.1";
    json["rabbitmq"]["port"] = 5672;
    json["rabbitmq"]["vhost"] = "/";
    json["rabbitmq"]["exchange_name"] = "exchange";
    json["rabbitmq"]["data_queue_name"] = "queue";
    const MineOJ::JudgeSideConfig server_config(json);
    EXPECT_EQ(server_config.rabbitmq_config.ip,"127.0.0.1");
    EXPECT_EQ(server_config.rabbitmq_config.port,5672);
    EXPECT_EQ(server_config.rabbitmq_config.username,"guest");
    EXPECT_EQ(server_config.rabbitmq_config.password,"guest");
    EXPECT_EQ(server_config.rabbitmq_config.vhost,"/");
    EXPECT_EQ(server_config.rabbitmq_config.exchange_name,"exchange");
    EXPECT_EQ(server_config.rabbitmq_config.data_queue_name,"queue");
}
