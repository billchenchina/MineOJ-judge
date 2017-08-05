/*
 * TcpHandler.h
 *
 *  Created on: 2017年8月5日
 *      Author: billchenchina
 */

#ifndef INCLUDE_RABBITMQ_TCPHANDLER_H_
#define INCLUDE_RABBITMQ_TCPHANDLER_H_

#include <amqpcpp.h>

namespace MineOJ {

class TcpHandler: public AMQP::TcpHandler {
public:
    TcpHandler();
    virtual ~TcpHandler();
    void onConnected(AMQP::TcpConnection *connection);
    void onError(AMQP::TcpConnection *connection, const char *message);
    void onClosed(AMQP::TcpConnection *connection);
    void monitor(AMQP::TcpConnection *connection, int fd, int flags);
};

} /* namespace MineOJ */

#endif /* INCLUDE_RABBITMQ_TCPHANDLER_H_ */
