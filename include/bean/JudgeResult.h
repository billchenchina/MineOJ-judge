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
    long long judge_id;
    long long problem_id;
    int score;
    JudgeType judge_type;
    JudgeStatus judge_status;
    std::string info;
    std::vector<JudgePoint> points;
private:
    Json::Value insertJson(Json::Value data_json){
        data_json["JudgeID"]=judge_id;
        data_json["ProblemID"]=problem_id;
        data_json["Score"]=score;
        data_json["JudgeType"]=judge_type;
        data_json["Info"]=info;
        // TODO 读入数组值可参考 https://sourceforge.net/p/jsoncpp/discussion/483465/thread/24cb7c88/
        // TO BE EDITED
        /*
        for(auto point:points){
            point.insertJson(data_json["Points"]);
        }
        */
        return data_json;
    }
};
}



#endif /* BEAN_JUDGERESULT_H_ */
