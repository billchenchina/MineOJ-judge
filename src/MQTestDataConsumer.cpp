/*
 * MQTestDataConsumer.cpp
 *
 *  Created on: 2018年1月21日
 *      Author: billchenchina
 */

#include "MQTestDataConsumer.h"

namespace MineOJ {
MQTestDataConsumer::MQTestDataConsumer(const RabbitmqConfig &config) :MQConsumer(config) {}
std::string MQTestDataConsumer::exec(const RabbitmqConfig &config) {
    auto *loop = EV_DEFAULT;
    _handler = new MyHandler(loop);
    AMQP::TcpConnection connection(_handler, address);
    AMQP::TcpChannel channel(&connection);
    std::string s;
    channel.consume(config.data_queue_name,AMQP::noack).onMessage([&channel,&connection,&s](const AMQP::Message &message, uint64_t deliveryTag, bool redelivered){
        s=std::string(message.body(),message.bodySize());
        channel.close();connection.close();
    });
    ev_run(loop);
    return s;
}
MQTestDataConsumer::~MQTestDataConsumer() {}

} /* namespace MineOJ */
