/*
 * JudgeResult.h
 *
 *  Created on: 2017年7月15日
 *      Author: billchenchina
 */

#ifndef BEAN_JUDGERESULT_H_
#define BEAN_JUDGERESULT_H_

#include <string>
#include <vector>

#include <jsoncpp/json.h>

#include <bean/JudgeStatus.h>
#include <bean/JudgePoint.h>
#include <bean/JudgeType.h>

namespace MineOJ{
class JudgeResult{
public:
    unsigned long long judge_id;
    unsigned long long problem_id;
    int score;
    JudgeType judge_type;
    JudgeStatus judge_status;
    std::string info;
    std::vector<JudgePoint> points;
    void parseJson(Json::Value data_json){
        judge_id=static_cast<long long>(data_json["judgeID"].asDouble());
        problem_id=static_cast<long long>(data_json["problemID"].asDouble());
        score=data_json["score"].asInt();
        judge_type=static_cast<JudgeType>(data_json["judgeType"].asInt());
        judge_status=static_cast<JudgeStatus>(data_json["judgeStatus"].asInt());
        info=data_json["info"].asString();
        Json::Value arrayJson=data_json["points"];
        int arr_size=arrayJson.size();
        for(auto i=0;i<arr_size;i++){
            JudgePoint judge_point;
            judge_point.parseJson(arrayJson[i]);
            points.push_back(judge_point);
        }
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
        data_json["judgeID"]=static_cast<double>(judge_id);
        data_json["problemID"]=static_cast<double>(problem_id);
        data_json["score"]=score;
        data_json["judgeType"]=judge_type;
        data_json["info"]=info;
        // TODO 读入数组值可参考 https://sourceforge.net/p/jsoncpp/discussion/483465/thread/24cb7c88/
        // TO BE EDITED
        Json::Value& data_node = data_json["points"];
        for(auto point:points){
            data_node.append(point.toJson());
        }

        return data_json;
    }
};
}



#endif /* BEAN_JUDGERESULT_H_ */
