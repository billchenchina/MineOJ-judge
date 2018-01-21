#ifndef BEAN_JUDGEDATA_H_
#define BEAN_JUDGEDATA_H_

#include <cstdint>
#include <string>

#include <json/json.h>

#include "bean/JudgeType.h"
#include "bean/JudgePoint.h"

namespace MineOJ {
class JudgeData {
public:
    std::int32_t judge_id;
    std::int32_t problem_id;
    std::string data_version;
    std::uint64_t memory_limit;
    std::uint64_t time_limit;
    JudgeType judge_type;
    std::string submit_code;
    std::vector<JudgePoint> judge_points;
    std::string compile_info;
    JudgeData() = default;
    JudgeData(const std::int32_t &judge_id, const std::int32_t &problem_id, const std::string &data_version,
            const std::uint64_t &memory_limit, const std::uint64_t &time_limit,
            const JudgeType &judge_type, const std::string &submit_code);
    JudgeData(const Json::Value &json);
    void parse_from_json(const Json::Value &json);
    Json::Value to_json() const;
    std::string to_string() const;

};

}

#endif // BEAN_JUDGEDATA_H_
