/*
 * JudgeCompileStep.h
 *
 *  Created on: 2018年1月26日
 *      Author: billchenchina
 */

#ifndef INCLUDE_BEAN_JUDGECOMPILESTEP_H_
#define INCLUDE_BEAN_JUDGECOMPILESTEP_H_
#include <string>
#include <vector>
namespace MineOJ {

class JudgeCompileStep {
public:
    JudgeCompileStep();
    virtual ~JudgeCompileStep();
    std::string compiler;
    std::vector<std::string> source_options;
    std::vector<std::string> output_options;
    std::vector<std::string> compiler_flags;

};

} /* namespace MineOJ */

#endif /* INCLUDE_BEAN_JUDGECOMPILESTEP_H_ */
