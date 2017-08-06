/*
 * Comparator.h
 *
 *  Created on: 2017年8月3日
 *      Author: billchenchina
 */

#ifndef INCLUDE_BEAN_Comparator_H_
#define INCLUDE_BEAN_Comparator_H_

#include <string>

namespace MineOJ {

class Comparator {
public:
    Comparator(std::string ans_file,std::string outputFile);
    void compare();
    bool getComparatoresult();
    virtual ~Comparator();
private:
    std::string ans_file;
    std::string output_file;
    bool result;
};

} /* namespace MineOJ */

#endif /* INCLUDE_BEAN_Comparator_H_ */
