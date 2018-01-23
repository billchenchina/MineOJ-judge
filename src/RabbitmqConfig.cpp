/*
 * RabbitmqConfig.cpp
 *
 *  Created on: 2018年1月20日
 *      Author: billchenchina
 */

#include <RabbitmqConfig.h>


RabbitmqConfig::~RabbitmqConfig() {}

RabbitmqConfig::RabbitmqConfig(const Json::Value &value) {
    ip = value["ip"].asString();
    port = value["port"].asInt();
    username = value["username"].asString();
    password = value["password"].asString();
    vhost = value["vhost"].asString();
    exchange_name = value["exchange_name"].asString();
    data_queue_name = value["data_queue_name"].asString();
    signal_queue_name = value["signal_queue_name"].asString();
    data_exchange_key = value["data_exchange_key"].asString();
}
