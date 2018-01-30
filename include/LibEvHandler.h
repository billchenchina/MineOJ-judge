/*
 * LibEvHandler.h
 *
 *  Created on: 2018年1月30日
 *      Author: billchenchina
 */

#ifndef INCLUDE_LIBEVHANDLER_H_
#define INCLUDE_LIBEVHANDLER_H_

#include <ev.h>
#include <amqpcpp.h>
#include <amqpcpp/libev.h>

namespace MineOJ {

/**
 *  Custom handler
 */
class LibEvHandler : public AMQP::LibEvHandler
{
private:
    /**
     *  Method that is called when a connection error occurs
     *  @param  connection
     *  @param  message
     */
    virtual void onError(AMQP::TcpConnection *connection, const char *message) override
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
    LibEvHandler(struct ev_loop *loop) : AMQP::LibEvHandler(loop) {}

    /**
     *  Destructor
     */
    virtual ~LibEvHandler() = default;
};
} /* namespace MineOJ */

#endif /* INCLUDE_LIBEVHANDLER_H_ */
