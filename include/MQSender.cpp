/*
 * MQSender.cpp
 *
 *  Created on: 2018年1月18日
 *      Author: billchenchina
 */

#include "MQSender.h"

namespace MineOJ {

MQSender::MQSender() :
        _url("amqp://guest:guest@localhost/"), _message(""), _handler(NULL) {
}
MQSender::MQSender(std::string url, std::string message) :
        _url(url), _message(message), _handler(NULL) {
}

MQSender::~MQSender() {
}
void MQSender::exec() {
    auto *loop = EV_DEFAULT;
    _handler = new MyHandler(loop);
    AMQP::TcpConnection connection(_handler, AMQP::Address(_url));
    AMQP::TcpChannel channel(&connection);
    channel.publish("EXCHANGE_NAME", "ROUTINGKEY", _message);
    channel.close();
    connection.close();
    ev_run(loop);
}

} /* namespace MineOJ */
