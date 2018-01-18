#include "bean/JudgeResult.h"
#include "bean/JudgeData.h"

#include <cstdint>

#include <string>
#include <vector>

#include <json/json.h>

MineOJ::JudgeResult::JudgeResult(std::int32_t judge_id, std::int32_t problem_id,
        std::uint32_t score, JudgeType judge_type, JudgeStatus judge_status,
        const std::string &info, const std::vector<JudgePoint> &points) :
        judge_id(judge_id), problem_id(problem_id), score(score), judge_type(
                judge_type), judge_status(judge_status), info(info), points(
                points) {
}

MineOJ::JudgeResult::JudgeResult(const Json::Value &json) :
        judge_id(json["judgeId"].asInt()), problem_id(
                json["problemId"].asInt()), score(json["score"].asUInt()), judge_type(
                static_cast<JudgeType>(json["judgeType"].asUInt())), judge_status(
                static_cast<JudgeStatus>(json["judgeStatus"].asUInt())), info(
                json["info"].asString()), points() {
    for (const auto &point : json["points"]) {
        points.push_back(JudgePoint(point));
    }
}

MineOJ::JudgeResult::JudgeResult(const MineOJ::JudgeData judge_data) :
        judge_id(judge_data.judge_id), problem_id(judge_data.problem_id), score(), judge_type(
                judge_data.judge_type), judge_status(), info(), points() {

}

Json::Value MineOJ::JudgeResult::to_json() const {
    Json::Value json;
    json["judgeId"] = judge_id;
    json["problemId"] = problem_id;
    json["score"] = score;
    json["judgeType"] = static_cast<std::uint8_t>(judge_type);
    json["judgeStatus"] = static_cast<std::uint8_t>(judge_status);
    json["info"] = info;
    if (judge_status != JudgeStatus::CompileError
            && judge_status != JudgeStatus::DangerousSystemCall
            && judge_status != JudgeStatus::JudgementFailed) {
        for (const auto &point : points) {
            json["points"].append(point.to_json());
        }
    }
    return json;
}
