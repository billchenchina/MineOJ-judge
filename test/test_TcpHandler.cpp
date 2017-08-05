/*
 * TcpHandler_test.cpp
 *
 *  Created on: 2017年8月5日
 *      Author: billchenchina
 */

#include "rabbitmq/TcpHandler.h"

#include <string>

#include <gtest/gtest.h>

TEST(RabbitMQTest,ConnectToServer){
    std::string amqp_address=R"()";

    // create an instance of your own tcp handler
    MineOJ::TcpHandler myHandler;

    // address of the server
    AMQP::Address address(amqp_address.c_str());

    // create a AMQP connection object
    AMQP::TcpConnection connection(&myHandler, address);

    // and create a channel
    AMQP::TcpChannel channel(&connection);

    // use the channel object to call the AMQP method you like
    channel.declareExchange("my-exchange", AMQP::fanout);
    channel.declareQueue("my-queue");
    channel.bindQueue("my-exchange", "my-queue", "my-routing-key");

}


namespace MineOJ {

} /* namespace MineOJ */
