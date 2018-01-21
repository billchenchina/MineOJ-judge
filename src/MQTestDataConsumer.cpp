/*
 * MQTestDataConsumer.cpp
 *
 *  Created on: 2018年1月21日
 *      Author: billchenchina
 */

#include "MQTestDataConsumer.h"

namespace MineOJ {

MQTestDataConsumer::MQTestDataConsumer() :MQConsumer(){}
MQTestDataConsumer::MQTestDataConsumer(const std::string &url) :MQConsumer(url) {}
MQTestDataConsumer::MQTestDataConsumer(const RabbitmqConfig &config) :MQConsumer(config) {}
std::string MQTestDataConsumer::exec() {
    auto *loop = EV_DEFAULT;
    _handler = new MyHandler(loop);
    AMQP::TcpConnection connection(_handler, address);
    AMQP::TcpChannel channel(&connection);
    std::string s;
    channel.consume("queue1",AMQP::noack).onMessage([&connection,&s](const AMQP::Message &message, uint64_t deliveryTag, bool redelivered){
        s=std::string(message.body());
        connection.close();
    });
    ev_run(loop);
    return s;
}
MQTestDataConsumer::~MQTestDataConsumer() {}

} /* namespace MineOJ */
