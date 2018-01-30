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
protected:
    Config()=delete;
public:
    virtual ~Config(){}
};

} /* namespace MineOJ */

#endif /* INCLUDE_CONFIG_H_ */




