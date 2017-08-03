/*
 * Comparer.h
 *
 *  Created on: 2017年8月3日
 *      Author: billchenchina
 */

#ifndef INCLUDE_BEAN_COMPARER_H_
#define INCLUDE_BEAN_COMPARER_H_

#include <string>

namespace MineOJ {

class Comparer {
public:
    Comparer(std::string ans_file,std::string outputFile);
    void compare();
    bool getCompareResult();
    virtual ~Comparer();
private:
    std::string ans_file;
    std::string output_file;
    bool result;
};

} /* namespace MineOJ */

#endif /* INCLUDE_BEAN_COMPARER_H_ */
