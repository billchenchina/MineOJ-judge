//Before the project complete,main.cpp will be exclude from all the build.
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <sstream>
#include <json/json.h>

#include "JudgeSideConfig.h"
#include "MQTestDataConsumer.h"
#include "bean/JudgeData.h"

int main(int argc,char **argv){
    std::ifstream config("default-config.json");
    std::stringstream buffer;
    buffer << config.rdbuf();
    Json::CharReaderBuilder builder;
    std::string errs;
    Json::Value value;
    Json::parseFromStream(builder, buffer, &value, &errs);

    MineOJ::JudgeSideConfig server_config(value);
    Json::StreamWriterBuilder write_builder;
    Json::CharReaderBuilder read_builder;
    for(;;)
    {
        MineOJ::MQTestDataConsumer consumer(server_config.rabbitmq_config);
        auto judge_data_str = consumer.exec();
        MineOJ::JudgeData judge_data;
        try
        {
            judge_data.parse_from_json(Json::Value(judge_data_str));
        }
        catch(const Json::LogicError &e)
        {
            std::cerr << "judge_data unvaliable!" << std::endl;
            std::cerr << "Please check!" << std::endl;
            continue;
        }

        /*
         * @TODO How to check the data version?
         *       1. Save a data version's SHA3 code to a file for every problem
         *       2. Use a MYSQL DataBase.
        if(judge_data.data_version)
        {

        }
        */

    }

    return 0;
}
