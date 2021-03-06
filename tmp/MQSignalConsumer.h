/*
 * MQSignalConsumer.h
 *
 *  Created on: 2018年1月21日
 *      Author: billchenchina
 */

#ifndef INCLUDE_MQSIGNALCONSUMER_H_
#define INCLUDE_MQSIGNALCONSUMER_H_

#include <MQConsumer.h>
#include "LibEvHandler.h"

namespace MineOJ {

class MQSignalConsumer: public MQConsumer {
public:
    MQSignalConsumer(const RabbitmqConfig &);
    virtual ~MQSignalConsumer();
    std::string exec();
private:
    MineOJ::LibEvHandler *_handler;
};

} /* namespace MineOJ */

#endif /* INCLUDE_MQSIGNALCONSUMER_H_ */
