#ifndef BEAN_JUDGEDATA_H_
#define BEAN_JUDGEDATA_H_

#include <cstdint>
#include <string>

#include <jsoncpp/json.h>

#include "bean/JudgeType.h"
#include "bean/JudgePoint.h"

namespace MineOJ
{
    class JudgeData
    {
    public:
        std::int32_t judge_id;
        std::int32_t problem_id;
        std::uint64_t memory_limit;
        std::uint64_t time_limit;
        JudgeType judge_type;
        std::string submit_code;
        std::vector<JudgePoint>judge_points;
        std::string compile_info;
        JudgeData() = default;
        JudgeData(std::int32_t judge_id, std::int32_t problem_id, std::uint64_t memory_limit, std::uint64_t time_limit, JudgeType judge_type, const std::string &submit_code);
        JudgeData(const Json::Value &json);

        Json::Value to_json() const;
        std::string to_string() const;

    };

/*
    class JudgeData{
    public:
        unsigned long long judge_id;
        unsigned long long problem_id;
        unsigned long long memory_limit;
        unsigned long long time_limit;
        JudgeType judge_type;
        std::string submit_code;
        void parseJson(const Json::Value data_json){
            judge_id        = data_json["judgeID"].asLargestInt();
            problem_id      = data_json["problemID"].asLargestInt();
            memory_limit    = data_json["memoryLimit"].asLargestInt();
            time_limit      = data_json["timeLimit"].asLargestInt();
            judge_type      = static_cast<JudgeType>(data_json["judgeType"].asInt());
            submit_code     = data_json["submitCode"].asString();

        }
        Json::Value toJson(){
            return castToJson();
        }
        std::string toString(){
            Json::FastWriter writer;
            Json::Value testJson=toJson();
            return writer.write(testJson);
        }
    private:
        Json::Value castToJson(){
            Json::Value data_json;
            data_json["judgeID"]        = static_cast<double>(judge_id);
            data_json["problemID"]      = static_cast<double>(problem_id);
            data_json["memoryLimit"]    = static_cast<double>(memory_limit);
            data_json["timeLimit"]      = static_cast<double>(time_limit);
            data_json["judgeType"]      = judge_type;
            data_json["submitCode"]     = submit_code;
            return data_json;
        }
    };
*/
}

#endif // BEAN_JUDGEDATA_H_
