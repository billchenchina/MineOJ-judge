/*
 * Config.h
 *
 *  Created on: 2018年1月19日
 *      Author: billchenchina
 */

#ifndef INCLUDE_CONFIG_H_
#define INCLUDE_CONFIG_H_

#include <json/json.h>

namespace MineOJ {


class Config {
public:
    Config();
    virtual ~Config();
    // virtual Json::Value to_json()=0;
    // virtual void parse_from_json(const Json::Value&)=0;
};

} /* namespace MineOJ */

#endif /* INCLUDE_CONFIG_H_ */
