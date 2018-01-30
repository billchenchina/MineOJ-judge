/*
 * JudgeSideConfig.h
 *
 *  Created on: 2018年1月19日
 *      Author: billchenchina
 */

#ifndef INCLUDE_JUDGESIDECONFIG_H_
#define INCLUDE_JUDGESIDECONFIG_H_
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

#include <json/json.h>

#include "Config.h"
#include "RabbitmqConfig.h"
#include "JudgeConfig.h"

namespace MineOJ {

class JudgeSideConfig{
public:
    JudgeSideConfig(const Json::Value &value);
    virtual ~JudgeSideConfig();
    RabbitmqConfig rabbitmq_config;
    JudgeConfig judge_config;
    // void parse_from_json(const Json::Value&);
    // Json::Value to_json()const;

};

} /* namespace MineOJ */

#endif /* INCLUDE_JUDGESIDECONFIG_H_ */
