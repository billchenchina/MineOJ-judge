/*
 * test_judgedata.cpp
 *
 *  Created on: 2017年7月17日
 *      Author: billchenchina
 */

#include <string>

#include <gtest/gtest.h>
#include <json/json.h>

#include "bean/JudgeData.h"

TEST(test_JudgeData, ConstructorByElements) {


    std::int32_t judge_id = 1;
    std::int32_t problem_id = 1;
    std::string data_version = "9f86d081884c7d659a2feaa0c55ad015a3bf4f1b2b0b822cd15d6c15b0f00a08";
    std::uint64_t memory_limit = 128 * 1024 * 1024;
    std::uint64_t time_limit = 1000;
    MineOJ::JudgeType judge_type = MineOJ::JudgeType::NormalJudge;
    std::string submit_code;
    MineOJ::JudgeData judge_data(judge_id, problem_id, data_version, memory_limit, time_limit,
            judge_type, submit_code);
    EXPECT_EQ(judge_data.judge_id, judge_id);
}

