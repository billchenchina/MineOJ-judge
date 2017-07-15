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

#include <bean/JudgeType.h>

namespace MineOJ{
/*
 * 评测数据
 */
class JudgeData{
public:
    unsigned long long judge_id;
    unsigned long long problem_id;
    unsigned long long memory_limit;
    unsigned long long time_limit;
    JudgeType judge_type;
    std::string submit_code;

};
}





#endif /* BEAN_JUDGEDATA_H_ */
