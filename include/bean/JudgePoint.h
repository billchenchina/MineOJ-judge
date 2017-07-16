/*
 * JudgePoint.h
 *
 *  Created on: 2017年7月15日
 *      Author: billchenchina
 */

#ifndef BEAN_JUDGEPOINT_H_
#define BEAN_JUDGEPOINT_H_

#include <string>

#include <bean/JudgeStatus.h>

namespace MineOJ{
class JudgePoint{
    long long use_time;
    long long use_memory;
    int score;
    JudgeStatus judge_status;
    std::string info;
};
}



#endif /* BEAN_JUDGEPOINT_H_ */
