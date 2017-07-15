/*
 * test_jsoncpp.cpp
 *
 *  Created on: 2017年6月28日
 *      Author: igronemyk
 */

#include <gtest/gtest.h>
#include <jsoncpp/json.h>
#include <string>

TEST(JsonCppTest, JsonToString){
    Json::FastWriter writer;
    Json::Value testJson;
    testJson["name"]="XiaoMing";
    testJson["id"]=1;
    testJson["finalGrade"]=100;
    testJson["Rank"]=1;
    testJson["isNO.1"]=true;
    std::string result = writer.write(testJson);
    EXPECT_EQ(result,"{\"Rank\":1,\"finalGrade\":100,\"id\":1,\"isNO.1\":true,\"name\":\"XiaoMing\"}\n");
}

TEST(JsonCppTest, StringToJson){
    std::string str = R"({"Rank":1,"finalGrade":100,"id":1,"isNO.1":true,"name":"XiaoMing"})";
    Json::Reader reader;
    Json::Value testJson;
    EXPECT_EQ(reader.parse(str, testJson, false), true);
    EXPECT_EQ(testJson["name"].asString(), "XiaoMing");
    EXPECT_EQ(testJson["id"].asInt(), 1);
    EXPECT_EQ(testJson["finalGrade"].asInt(), 100);
    EXPECT_EQ(testJson["Rank"].asInt(), 1);
    EXPECT_EQ(testJson["isNO.1"].asBool(), true);
}
