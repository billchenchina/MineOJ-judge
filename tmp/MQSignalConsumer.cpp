/*
 * MQSignalConsumer.cpp
 *
 *  Created on: 2018年1月21日
 *      Author: billchenchina
 */

#include <MQSignalConsumer.h>

namespace MineOJ {

MQSignalConsumer::MQSignalConsumer(const RabbitmqConfig &config) :MQConsumer(config) {}

MQSignalConsumer::~MQSignalConsumer() {}

std::string MQSignalConsumer::exec() {
    auto *loop = EV_DEFAULT;
    auto handler = new AMQP::LibEvHandler(loop);
    AMQP::TcpConnection connection(handler, address);
    AMQP::TcpChannel channel(&connection);
    std::string s;
    // @TODO: make the message received by specific judge
    channel.consume("queue1",AMQP::noack).onMessage([&channel,&connection,&s](const AMQP::Message &message, uint64_t deliveryTag, bool redelivered){
        s=std::string(message.body());
        channel.close();connection.close();
    });
    ev_run(loop);
    return s;
}

} /* namespace MineOJ */
