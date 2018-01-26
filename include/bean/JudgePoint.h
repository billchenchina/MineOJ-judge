/*
 * JudgePoint.h
 *
 *  Created on: 2017年7月15日
 *      Author: billchenchina
 */

#ifndef INCLUDE_BEAN_JUDGEPOINT_H_
#define INCLUDE_BEAN_JUDGEPOINT_H_

#include <cstdint>

#include <string>

#include <json/json.h>

#include "bean/JudgeStatus.h"

namespace MineOJ {
class JudgePoint {
public:
    std::uint64_t time;
    std::uint64_t memory;
    std::uint32_t score;
    JudgeStatus judge_status;
    std::string info;
    JudgePoint() = default;
    JudgePoint(std::uint64_t time, std::uint64_t memory, std::uint32_t score,
            JudgeStatus judge_status, const std::string &info);
    JudgePoint(const Json::Value &json);

    Json::Value to_json() const;
};
}

#endif /* INCLUDE_BEAN_JUDGEPOINT_H_ */
