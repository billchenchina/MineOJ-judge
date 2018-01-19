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
    Json::Value json;
    json["rabbitmq"]["username"] = "guest";
    json["rabbitmq"]["password"] = "guest";
    json["rabbitmq"]["ip"] = "127.0.0.1";
    json["rabbitmq"]["port"] = 5672;
    json["rabbitmq"]["vhost"] = "/";
    json["rabbitmq"]["exchange_name"] = "exchange";
    json["rabbitmq"]["queue_name"] = "queue";

    std::int32_t judge_id = 1;
    std::int32_t problem_id = 1;
    std::uint64_t memory_limit = 128 * 1024 * 1024;
    std::uint64_t time_limit = 1000;
    MineOJ::JudgeType judge_type = MineOJ::JudgeType::NormalJudge;
    std::string submit_code;
    MineOJ::JudgeData judge_data(judge_id, problem_id, memory_limit, time_limit,
            judge_type, submit_code);
    EXPECT_EQ(judge_data.judge_id, judge_id);
}

/*
 TEST(JudgeDataTest, StringToJudgeData){
 std::string str=R"({"judgeID":1,"problemID":1,"memoryLimit":100,"timeLimit":100,"judgeType":0,"submitCode":"testCode"})";
 Json::Value in_value;
 Json::Reader reader;
 reader.parse(str,in_value);
 MineOJ::JudgeData judge_data;
 judge_data.parseJson(in_value);
 Json::Value to_value;
 to_value=judge_data.toJson();
 Json::FastWriter writer;
 std::string outstr=writer.write(to_value);
 EXPECT_EQ(str,outstr);
 }
 */
