/*
 * JudgeConfig.cpp
 *
 *  Created on: 2018年1月24日
 *      Author: billchenchina
 */

#include <JudgeConfig.h>

namespace MineOJ {

JudgeConfig::JudgeConfig(const Json::Value &value):
        work_path(value["work_path"].asString()),
        data_path(value["data_path"].asString()),
        web_host(value["web_host"].asString()),
        app_key(value["app_key"].asString()) {}

JudgeConfig::~JudgeConfig() {}

} /* namespace MineOJ */
