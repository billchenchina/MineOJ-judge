/*
 * JudgeConfig.cpp
 *
 *  Created on: 2018年1月24日
 *      Author: billchenchina
 */

#include <JudgeConfig.h>

namespace MineOJ {

JudgeConfig::JudgeConfig(const Json::Value &value):work_dir(value["work_dir"].asString()),data_dir(value["data_dir"].asString()) {}

JudgeConfig::~JudgeConfig() {}

} /* namespace MineOJ */
