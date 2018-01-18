#ifndef BEAN_JUDGERESULT_H_
#define BEAN_JUDGERESULT_H_

#include <cstdint>

#include <string>
#include <vector>

#include <json/json.h>

#include "bean/JudgeStatus.h"
#include "bean/JudgePoint.h"
#include "bean/JudgeType.h"
#include "bean/JudgeData.h"

namespace MineOJ {
class JudgeResult {
public:
    std::int32_t judge_id;
    std::int32_t problem_id;
    std::uint32_t score;
    JudgeType judge_type;
    JudgeStatus judge_status;
    std::string info;
    std::vector<JudgePoint> points;

    JudgeResult() = default;
    JudgeResult(std::int32_t judge_id, std::int32_t problem_id,
            std::uint32_t score, JudgeType judge_type, JudgeStatus judge_status,
            const std::string &info, const std::vector<JudgePoint> &points);
    JudgeResult(const Json::Value &json);
    JudgeResult(const JudgeData judge_data);
    Json::Value to_json() const;
    std::string to_string() const;
};
}

#endif /* BEAN_JUDGERESULT_H_ */
