/*
 * JudgeRunStep.h
 *
 *  Created on: 2018年1月26日
 *      Author: billchenchina
 */

#ifndef INCLUDE_BEAN_JUDGERUNSTEP_H_
#define INCLUDE_BEAN_JUDGERUNSTEP_H_

#include <string>
#include <vector>
#include <experimental/filesystem>
#include "bean/JudgePoint.h"

namespace MineOJ {

class JudgeRunStep {
public:
    JudgeRunStep();
    virtual ~JudgeRunStep();
    std::string program_name;
    std::string in;
    std::string out;
    std::vector
};

} /* namespace MineOJ */

#endif /* INCLUDE_BEAN_JUDGERUNSTEP_H_ */
