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

#include <bean/JudgeStatus.h>
#include <bean/JudgePoint.h>
namespace MineOJ{
class JudgeResult{
public:
    long long judge_id;
    long long problem_id;
    int score;
    JudgeStatus judge_status;
    std::string info;
    std::vector<JudgePoint> points;
};
}



#endif /* BEAN_JUDGERESULT_H_ */
