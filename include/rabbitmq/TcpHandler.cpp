/*
 * TcpHandler.cpp
 *
 *  Created on: 2017年8月5日
 *      Author: billchenchina
 */

#include <rabbitmq/TcpHandler.h>

namespace MineOJ {

TcpHandler::TcpHandler() {
    // TODO Auto-generated constructor stub

}

TcpHandler::~TcpHandler() {
    // TODO Auto-generated destructor stub
}

/**
 *  Method that is called by the AMQP library when the login attempt
 *  succeeded. After this method has been called, the connection is ready
 *  to use.
 *  @param  connection      The connection that can now be used
 */
void TcpHandler::onConnected(AMQP::TcpConnection *connection)
{
    // @todo
    //  add your own implementation, for example by creating a channel
    //  instance, and start publishing or consuming
}

/**
 *  Method that is called by the AMQP library when a fatal error occurs
 *  on the connection, for example because data received from RabbitMQ
 *  could not be recognized.
 *  @param  connection      The connection on which the error occured
 *  @param  message         A human readable error message
 */
void TcpHandler::onError(AMQP::TcpConnection *connection, const char *message)
{
    // @todo
    //  add your own implementation, for example by reporting the error
    //  to the user of your program, log the error, and destruct the
    //  connection object because it is no longer in a usable state
}

/**
 *  Method that is called when the connection was closed. This is the
 *  counter part of a call to Connection::close() and it confirms that the
 *  connection was correctly closed.
 *
 *  @param  connection      The connection that was closed and that is now unusable
 */
void TcpHandler::onClosed(AMQP::TcpConnection *connection) {}

/**
 *  Method that is called by the AMQP-CPP library when it wants to interact
 *  with the main event loop. The AMQP-CPP library is completely non-blocking,
 *  and only make "write()" or "read()" system calls when it knows in advance
 *  that these calls will not block. To register a filedescriptor in the
 *  event loop, it calls this "monitor()" method with a filedescriptor and
 *  flags telling whether the filedescriptor should be checked for readability
 *  or writability.
 *
 *  @param  connection      The connection that wants to interact with the event loop
 *  @param  fd              The filedescriptor that should be checked
 *  @param  flags           Bitwise or of AMQP::readable and/or AMQP::writable
 */
void TcpHandler::monitor(AMQP::TcpConnection *connection, int fd, int flags)
{
    // @todo
    //  add your own implementation, for example by adding the file
    //  descriptor to the main application event loop (like the select() or
    //  poll() loop). When the event loop reports that the descriptor becomes
    //  readable and/or writable, it is up to you to inform the AMQP-CPP
    //  library that the filedescriptor is active by calling the
    //  connection->process(fd, flags) method.
}

} /* namespace MineOJ */
