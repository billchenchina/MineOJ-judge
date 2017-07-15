/*
 * test_json.cpp
 *
 *  Created on: 2017年6月28日
 *      Author: igronemyk
 */

#include <gtest/gtest.h>
#include <json/json.hpp>
#include <string>

using json=nlohmann::json;

TEST(JsonTest, JsonToString){
    json testJson;
    testJson["name"]="XiaoMing";
    testJson["id"]=1;
    testJson["finalGrade"]=100;
    testJson["Rank"]=1;
    testJson["isNO.1"]=true;
    EXPECT_EQ(testJson.dump(),"{\"Rank\":1,\"finalGrade\":100,\"id\":1,\"isNO.1\":true,\"name\":\"XiaoMing\"}");
}

TEST(JsonTest, StringToJson){
    json testJson = R"({"Rank":1,"finalGrade":100,"id":1,"isNO.1":true,"name":"XiaoMing"})"_json;
    EXPECT_EQ(testJson["name"].get<std::string>(),"XiaoMing");
    EXPECT_EQ(testJson["id"].get<int>(),1);
    EXPECT_EQ(testJson["finalGrade"].get<int>(),100);
    EXPECT_EQ(testJson["Rank"].get<int>(),1);
    EXPECT_EQ(testJson["isNO.1"].get<bool>(),true);
}
