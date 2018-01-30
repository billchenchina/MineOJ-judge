/*
 * MQTestDataConsumer.h
 *
 *  Created on: 2018年1月21日
 *      Author: billchenchina
 */

#ifndef INCLUDE_MQTESTDATACONSUMER_H_
#define INCLUDE_MQTESTDATACONSUMER_H_

#include <MQConsumer.h>
#include <LibEvHandler.h>

namespace MineOJ {

class MQTestDataConsumer: public MQConsumer {
public:
    MQTestDataConsumer(const RabbitmqConfig &);
    std::string exec(const RabbitmqConfig &);
    virtual ~MQTestDataConsumer();
private:
    MineOJ::LibEvHandler *_handler;
};

} /* namespace MineOJ */

#endif /* RELEASE_MQTESTDATACONSUMER_H_ */
