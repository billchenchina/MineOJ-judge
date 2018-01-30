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



};

} /* namespace MineOJ */

#endif /* INCLUDE_MQCONSUMER_H_ */
