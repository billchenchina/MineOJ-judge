#include <cstdint>

#include <string>
#include <vector>

#include <gtest/gtest.h>
#include <json/json.h>

#include "bean/JudgeResult.h"

TEST(test_JudgeResult, ConstructorByElements) {
    std::int32_t judge_id = 1;
    std::int32_t problem_id = 1;
    std::uint32_t score = 100;
    MineOJ::JudgeType judge_type = MineOJ::JudgeType::NormalJudge;
    MineOJ::JudgeStatus judge_status = MineOJ::JudgeStatus::Accept;
    std::string info;
    std::vector<MineOJ::JudgePoint> points { MineOJ::JudgePoint(), MineOJ::JudgePoint() };
    MineOJ::JudgeResult result(judge_id, problem_id, score, judge_type, judge_status, info, points);

}

