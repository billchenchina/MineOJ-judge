/*
 * JudgeSideConfig.cpp
 *
 *  Created on: 2018年1月19日
 *      Author: billchenchina
 */

#include "JudgeSideConfig.h"


namespace MineOJ {


JudgeSideConfig::~JudgeSideConfig() {
    // TODO Auto-generated destructor stub
}
JudgeSideConfig::JudgeSideConfig(const Json::Value &value):rabbitmq_config(value["rabbitmq"]) {}
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
