/*
 * MQSender.h
 *
 *  Created on: 2018年1月18日
 *      Author: billchenchina
 */

#ifndef INCLUDE_MQSENDER_H_
#define INCLUDE_MQSENDER_H_

#include <string>

#include <amqpcpp.h>
#include <amqpcpp/libev.h>
#include <ev.h>

namespace MineOJ {

class MQSender {
public:
    MQSender();
    MQSender(std::string url, std::string message);
    virtual ~MQSender();
    void exec();
private:
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
    std::string _url;
    std::string _message;
    MyHandler* _handler;
};

} /* namespace MineOJ */

#endif /* INCLUDE_MQSENDER_H_ */

