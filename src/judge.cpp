/*
 * judge.cpp
 *
 *  Created on: 2017年8月3日
 *      Author: billchenchina
 */
#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>

#include "bean/JudgeData.h"
#include "bean/JudgeResult.h"


MineOJ::JudgeResult judge_cpp(MineOJ::JudgeData judge_data){
    MineOJ::JudgeResult judge_result(judge_data);
    // @TODO
    system("mkdir judge_dir");
    std::ofstream code_out("judge_dir/code.cpp");
    unsigned int code_max_length=100*1024;
    code_out.write(judge_data.submit_code.c_str(),code_max_length);
    code_out.close();
    std::string compile_command="g++ judge_dir/code.cpp -o judge_dir/code -lm ";
    compile_command+=judge_data.compile_info;
    system(compile_command.c_str());
    unsigned int data_max_length=50*1024*1024;
    for(auto point:judge_data.judge_points){
        std::ofstream point_out("judge_dir/data.in");
        point_out.write(point.in_data.c_str(),data_max_length);
        point_out.close();
        std::string run_command="judge_dir/code < judge_dir/data.in > judge_dir/data.out";
        system(run_command.c_str());
    }
    return judge_result;
}


namespace MineOJ{

}
