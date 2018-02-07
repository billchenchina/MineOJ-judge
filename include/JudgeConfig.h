/*
 * JudgeConfig.h
 *
 *  Created on: 2018年1月24日
 *      Author: billchenchina
 */

#ifndef INCLUDE_JUDGECONFIG_H_
#define INCLUDE_JUDGECONFIG_H_

#include <string>

#include <Config.h>


namespace MineOJ {

class JudgeConfig {
public:
    JudgeConfig(const Json::Value &value);
    virtual ~JudgeConfig();
    std::string data_path;
    std::string work_path;
    std::string web_host;
    std::string app_key;

};

} /* namespace MineOJ */

#endif /* INCLUDE_JUDGECONFIG_H_ */
