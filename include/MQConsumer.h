/*
 * MQConsumer.h
 *
 *  Created on: 2018年1月20日
 *      Author: billchenchina
 */

#ifndef INCLUDE_MQCONSUMER_H_
#define INCLUDE_MQCONSUMER_H_

#include <string>
#include <amqpcpp.h>
#include <amqpcpp/libev.h>
#include <ev.h>
#include "RabbitmqConfig.h"

namespace MineOJ {

class MQConsumer {
public:
    MQConsumer(const RabbitmqConfig &);
    virtual ~MQConsumer();
    AMQP::Address address;
public:
    /**
     *  Custom handler
     */
    class MyHandler: public AMQP::LibEvHandler {
    private:
        /**
         *  Method that is called when a connection error occurs
         *  @param  connection
         *  @param  message
         */
        virtual void onError(AMQP::TcpConnection *connection,
                const char *message) override
                {
            std::cout << "error: " << message << std::endl;
        }

        /**
         *  Method that is called when the TCP connection ends up in a connected state
         *  @param  connection  The TCP connection
         */
        virtual void onConnected(AMQP::TcpConnection *connection) override
        {
            std::cout << "connected" << std::endl;
        }

    public:
        /**
         *  Constructor
         *  @param  ev_loop
         */
        MyHandler(struct ev_loop *loop) :
                AMQP::LibEvHandler(loop) {
        }

        /**
         *  Destructor
         */
        virtual ~MyHandler() {
        }
    };


};

} /* namespace MineOJ */

#endif /* INCLUDE_MQCONSUMER_H_ */
