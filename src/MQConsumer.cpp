/*
 * MQConsumer.cpp
 *
 *  Created on: 2018年1月20日
 *      Author: billchenchina
 */

#include "MQConsumer.h"

namespace MineOJ {

MQConsumer::MQConsumer() :_address("amqp://guest:guest@localhost/"),_handler(NULL) {}

MQConsumer::MQConsumer(const std::string &url) :_address(url),_handler(NULL) {}

MQConsumer::MQConsumer(const RabbitmqConfig &config) :_handler(NULL),_address(AMQP::Address(config.ip, config.port, AMQP::Login(config.username,config.password), config.vhost)) {}

MQConsumer::~MQConsumer() {}

std::string MQConsumer::exec() {
    auto *loop = EV_DEFAULT;
    _handler = new MyHandler(loop);
    AMQP::TcpConnection connection(_handler, _address);
    AMQP::TcpChannel channel(&connection);
    std::string s;
    channel.consume("queue1",AMQP::noack).onMessage([&connection,&s](const AMQP::Message &message, uint64_t deliveryTag, bool redelivered){
        s=std::string(message.body());
        connection.close();
    });
    ev_run(loop);
    return s;
}
} /* namespace MineOJ */
