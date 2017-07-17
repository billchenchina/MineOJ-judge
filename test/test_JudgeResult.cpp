/*
 * test_JudgeResult.cpp
 *
 *  Created on: 2017年7月17日
 *      Author: billchenchina
 */


#include <string>

#include <gtest/gtest.h>
#include <jsoncpp/json.h>

#include <bean/JudgeResult.h>

TEST(JudgeResultTest, StringToJudgeResult){
    std::string str = R"({"judgeID":1,"problemID":1,"score":100,"judgeType":0,"judgeStatus":1,"info":"JudgeResultInfo","points":[{"useTime":100,"useMemory":100,"score":100,"judgeStatus":0,"info":"info1"},{"useTime":20,"useMemory":20,"score":0,"judgeStatus":1,"info":"info2"}]})";
    Json::Value in_value;
    Json::Reader reader;
    reader.parse(str,in_value);
    MineOJ::JudgeResult judge_result;
    judge_result.parseJson(in_value);
    Json::Value to_value;
    to_value=judge_result.toJson();
    Json::FastWriter writer;
    std::string outstr=writer.write(to_value);
    EXPECT_EQ(str,outstr);
}


