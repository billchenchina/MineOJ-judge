#include "bean/JudgeData.h"

#include <cstdint>

#include <string>

#include <json/json.h>

MineOJ::JudgeData::JudgeData(std::int32_t judge_id, std::int32_t problem_id,
        std::uint64_t memory_limit, std::uint64_t time_limit,
        JudgeType judge_type, const std::string &submit_code) :
        judge_id(judge_id), problem_id(problem_id), memory_limit(memory_limit), time_limit(
                time_limit), judge_type(judge_type), submit_code(submit_code) {
}

MineOJ::JudgeData::JudgeData(const Json::Value &json) :
        judge_id(json["judgeId"].asInt()), problem_id(
                json["problemId"].asInt()), memory_limit(
                json["memoryLimit"].asUInt64()), time_limit(
                json["timeLimit"].asUInt64()), judge_type(
                static_cast<JudgeType>(json["judgeType"].asUInt())), submit_code(
                json["submitCode"].asString()) {
}

Json::Value MineOJ::JudgeData::to_json() const {
    Json::Value json;
    json["judgeId"] = judge_id;
    json["problemId"] = problem_id;
    json["memoryLimit"] = static_cast<double>(memory_limit);
    json["timeLimit"] = static_cast<double>(time_limit);
    json["judgeType"] = static_cast<std::uint8_t>(judge_type);
    json["submitCode"] = submit_code;
    return json;
}
