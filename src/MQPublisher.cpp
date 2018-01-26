/*
 * MQPublisher.cpp
 *
 *  Created on: 2018年1月18日
 *      Author: billchenchina
 */

#include "MQPublisher.h"

namespace MineOJ {

MQPublisher::MQPublisher() :_address("amqp://guest:guest@localhost/"), _message(""), _handler(NULL) {}

MQPublisher::MQPublisher(const std::string &url, const std::string &message) :_address(url), _message(message), _handler(NULL) {}

MQPublisher::MQPublisher(const RabbitmqConfig &config,const std::string &message) :_message(message), _handler(NULL) ,_address(AMQP::Address(config.ip,config.port,AMQP::Login(config.username,config.password),config.vhost)) {}

MQPublisher::~MQPublisher() {}
/*
void MQPublisher::exec() {
    auto *loop = EV_DEFAULT;
    _handler = new MyHandler(loop);
    AMQP::TcpConnection connection(_handler, _address);
    AMQP::TcpChannel channel(&connection);
    channel.publish("exchange1", "key", _message);
    channel.close();
    connection.close();
    ev_run(loop);
}
*/

} /* namespace MineOJ */
