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

class JudgeConfig: public Config {
public:
    JudgeConfig(const Json::Value &value);
    virtual ~JudgeConfig();
    std::string data_dir;
    std::string work_dir;

};

} /* namespace MineOJ */

#endif /* INCLUDE_JUDGECONFIG_H_ */
