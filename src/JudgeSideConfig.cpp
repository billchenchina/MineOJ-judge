/*
 * JudgeSideConfig.cpp
 *
 *  Created on: 2018年1月19日
 *      Author: billchenchina
 */

#include "JudgeSideConfig.h"


namespace MineOJ {


JudgeSideConfig::~JudgeSideConfig() {
}
JudgeSideConfig::JudgeSideConfig(const Json::Value &value):rabbitmq_config(value["rabbitmq"]),judge_config(value["settings"]) {}
/*
 * @TODO
void JudgeSideConfig::parse_from_json(const Json::Value& value)
{

}
Json::Value JudgeSideConfig::to_json() const
{

}
*/

} /* namespace MineOJ */
