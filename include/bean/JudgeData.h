/*
 * @file    JudgeData.h
 * @brief   JudgeData 类
 * @details JudgeData 类，用于实现评测数据
 * @author  billchenchina
 * @date    2017年7月15日
 *
 */

#ifndef BEAN_JUDGEDATA_H_
#define BEAN_JUDGEDATA_H_

#include <string>

#include <jsoncpp/json.h>

#include <bean/JudgeType.h>
#include <bean/JudgePoint.h>

namespace MineOJ{
/*
 * 评测数据
 */
class JudgeData{
public:
    double judge_id;
    double problem_id;
    double memory_limit;
    double time_limit;
    JudgeType judge_type;
    std::string submit_code;
    void parseJson(const Json::Value data_json){
        judge_id        = data_json["JudgeID"].asLargestInt();
        problem_id      = data_json["ProblemID"].asLargestInt();
        memory_limit    = data_json["MemoryLimit"].asLargestInt();
        time_limit      = data_json["TimeLimit"].asLargestInt();
        //judge_type      = data_json["JudgeType"].asInt();
        submit_code     = data_json["SubmitCode"].asString();

    }
    Json::Value toJson(){
        Json::Value data_json;
        insertJson(data_json);
        return data_json;
    }
    std::string toString(){
        Json::FastWriter writer;
        Json::Value testJson=toJson();
        return writer.write(testJson);
    }
private:
    void insertJson(Json::Value &data_json){

        data_json["JudgeID"]        = judge_id;
        data_json["JudgeType"]      = judge_type;
        data_json["MemoryLimit"]    = memory_limit;
        data_json["TimeLimit"]      = time_limit;
        data_json["ProblemID"]      = problem_id;
        data_json["SubmitCode"]     = submit_code;

        // TODO http://www.cnblogs.com/yxwkf/p/4020591.html
        // 由于JsonCpp不支持long long，故此处是否应改为double暂需讨论
        // 暂时已更改为double
        return;
    }
};
}





#endif /* BEAN_JUDGEDATA_H_ */
