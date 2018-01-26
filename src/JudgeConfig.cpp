/*
 * JudgeConfig.cpp
 *
 *  Created on: 2018年1月24日
 *      Author: billchenchina
 */

#include <JudgeConfig.h>

namespace MineOJ {

JudgeConfig::JudgeConfig(const Json::Value &value):work_path(value["work path"].asString()),data_path(value["data path"].asString()) {}

JudgeConfig::~JudgeConfig() {}

} /* namespace MineOJ */
