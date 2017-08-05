/*
 * TcpHandler_test.cpp
 *
 *  Created on: 2017年8月5日
 *      Author: billchenchina
 */

#include "rabbitmq/TcpHandler.h"

#include <string>

#include <gtest/gtest.h>

TEST(RabbitMQTest,writeToServer){
    const std::string amqp_address=R"()";
    const std::string queue_name=R"(MineOJ-Judger)";
    const std::string exchange_name=R"()";
    const std::string routing_key=R"()";
    // create an instance of your own tcp handler
    MineOJ::TcpHandler myHandler;

    // address of the server
    AMQP::Address address(amqp_address);

    // create a AMQP connection object
    AMQP::TcpConnection connection(&myHandler, address);
    // and create a channel
    AMQP::TcpChannel channel(&connection);
    // use the channel object to call the AMQP method you like
    channel.declareQueue(queue_name);
    channel.declareExchange(AMQP::direct);
    channel.bindQueue(exchange_name,queue_name,routing_key);

}


namespace MineOJ {

} /* namespace MineOJ */
