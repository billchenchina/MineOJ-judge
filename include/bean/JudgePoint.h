/*
 * JudgePoint.h
 *
 *  Created on: 2017年7月15日
 *      Author: billchenchina
 */

#ifndef BEAN_JUDGEPOINT_H_
#define BEAN_JUDGEPOINT_H_

#include <string>

#include <jsoncpp/json.h>

#include <bean/JudgeStatus.h>

namespace MineOJ{
class JudgePoint{
    double use_time;
    double use_memory;
    int score;
    JudgeStatus judge_status;
    std::string info;
    // TODO 读入数组值可参考 https://sourceforge.net/p/jsoncpp/discussion/483465/thread/24cb7c88/
    // TO BE EDITED
    void insertJson(Json::Value &data_json){

        //data_json["UseTime"]=use_time;
        // TODO http://www.cnblogs.com/yxwkf/p/4020591.html
        // 由于JsonCpp不支持long long，故此处是否应改为double暂需讨论
        // 暂时已更改为double

        data_json["UseMemory"]=use_memory;
        data_json["Score"]=score;
        data_json["JudgeStatus"]=judge_status;
        data_json["Info"]=info;
    }

};
}



#endif /* BEAN_JUDGEPOINT_H_ */
