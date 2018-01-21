/*
 * MQConsumer.cpp
 *
 *  Created on: 2018年1月20日
 *      Author: billchenchina
 */

#include "MQConsumer.h"

namespace MineOJ {

MQConsumer::MQConsumer() :address("amqp://guest:guest@localhost/") {}

MQConsumer::MQConsumer(const std::string &url) :address(url) {}

MQConsumer::MQConsumer(const RabbitmqConfig &config) :address(AMQP::Address(config.ip, config.port, AMQP::Login(config.username,config.password), config.vhost)) {}

MQConsumer::~MQConsumer() {}


} /* namespace MineOJ */
