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
    Json::Value config_value;
    {

        std::stringstream buffer;
        buffer << config.rdbuf();
        Json::CharReaderBuilder builder;
        std::string errs;

        Json::parseFromStream(builder, buffer, &config_value, &errs);
    }

    MineOJ::JudgeSideConfig server_config(config_value);
    Json::StreamWriterBuilder write_builder;
    Json::CharReaderBuilder read_builder;
    for(;;)
    {
        MineOJ::MQTestDataConsumer consumer(server_config.rabbitmq_config);
        auto judge_data_str = consumer.exec(server_config.rabbitmq_config);
        MineOJ::JudgeData judge_data;
        Json::Value judge_json_value;
        try
        {
            // init json builder
            Json::CharReaderBuilder builder;
            builder["collectComments"] = false;
            std::string errs;
            std::stringstream ss(judge_data_str);
            // parse
            parseFromStream(builder, ss, &judge_json_value, &errs);
            judge_data.parse_from_json(judge_json_value);
        }
        catch(const Json::LogicError &e)
        {
            std::cerr << "judge_data unvaliable!" << std::endl;
            std::cerr << "Please check!" << std::endl;
            std::cerr << judge_data_str << std::endl;
            continue;
        }


    }

    return 0;
}
