/*
 * JudgeSideConfig.cpp
 *
 *  Created on: 2018年1月19日
 *      Author: billchenchina
 */

#include "JudgeSideConfig.h"


namespace MineOJ {

JudgeSideConfig::JudgeSideConfig() {
    std::ifstream config("default-config.json");
    std::stringstream buffer;
    buffer << config.rdbuf();
    Json::CharReaderBuilder builder;
    std::string errs;
    Json::Value value;
    Json::parseFromStream(builder, buffer, &value, &errs);
    *this = JudgeSideConfig(value);
}

JudgeSideConfig::~JudgeSideConfig() {
    // TODO Auto-generated destructor stub
}
JudgeSideConfig::JudgeSideConfig(const Json::Value &value) {
    this->rabbitmq_config = RabbitmqConfig(value["rabbitmq"]);
}
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
