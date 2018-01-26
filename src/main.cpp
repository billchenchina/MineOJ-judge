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
    Json::CharReaderBuilder builder;
    std::string json_parse_errs;

    std::stringstream json_parse_ss;
    json_parse_ss << config.rdbuf();
    Json::parseFromStream(builder, json_parse_ss, &config_value, &json_parse_errs);
    json_parse_ss.clear();

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
            json_parse_ss << judge_data_str;
            parseFromStream(builder, json_parse_ss, &judge_json_value, &json_parse_errs);
            judge_data.parse_from_json(judge_json_value);
            json_parse_ss.clear();
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
